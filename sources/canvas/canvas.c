/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:31:47 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/28 17:24:36 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../includes/miniRT.h"


void	fill_canvas(size_t width, size_t height)
{
	size_t			y_pixel;
	size_t			x_pixel;
	t_ray			*ray;
	t_data			*data;
	t_hit_obj		*hit_obj;

	data = get_data();
	y_pixel = 0;
	while (y_pixel < height)
	{
		x_pixel = 0;
		while (x_pixel < width)
		{
			ray = create_ray(x_pixel, y_pixel);
			hit_obj = find_hit_pt(data->objects, ray);
			// mlx_put_pixel(data->image, x_pixel, y_pixel, \
			// 				find_hit_pt(data->objects, ray));
			mlx_put_pixel(data->image, x_pixel, y_pixel, \
							calc_pixel_color(hit_obj, ray));
			x_pixel++;
		}
		y_pixel++;
	}
}

t_hit_obj	*find_hit_pt(t_object **objects, t_ray *ray)
{
	t_hit_obj	*hit_obj;
	float		hit_pt;
	int			object_idx;

	// float		hit_pt_min[2];
	object_idx = 0;
// printf("hit_obj->pt: %f\n", hit_obj->pt);
	// hit_pt = 9999.0;
	// hit_pt_min[1] = 2.0;
	hit_obj = malloc(1 * sizeof(t_hit_obj));
	hit_obj->pt = 9999.0;
	while (objects[object_idx] != NULL)
	{
		if (objects[object_idx]->obj_name <= LIGHT)
		{
			object_idx++;
			continue ;
		}
		hit_pt = get_hit_pt_ft()[objects[object_idx]->obj_name](objects[object_idx], ray);
// printf("hit_pt: %f\n", hit_pt);
		if (hit_pt < hit_obj->pt && hit_pt >= 1)
		{
			hit_obj->pt = hit_pt;
// printf("hit_obj->pt: %f\n", hit_obj->pt);
			hit_obj->obj = objects[object_idx];
		}
		object_idx++;
	}
// printf("hit_obj->pt: %f\n\n\n", hit_obj->pt);
	if (hit_obj->pt >= 1)
	{
// printf("hit_obj->pt >= 1\n");
		return (hit_obj);
		// return (objects[(int)hit_pt_min[1]]->s_sphere.color.pixel_color);
	}
	else
	{
printf("hit_obj->pt < 1\n");
		return (NULL);
	}
}

uint32_t	calc_pixel_color(t_hit_obj *hit_obj, t_ray *ray)
{
	t_tuple	*normal_vec;
	t_color	color;

	if (hit_obj == NULL)
		return (2345678);

// printf("hit_obj->obj->obj_name: %d\n", hit_obj->obj->obj_name);
// printf("still alive in calc_pixel_color\n\n");
	normal_vec = get_normal_vec_ft()[hit_obj->obj->obj_name](hit_obj, ray);
	color = set_color((normal_vec->x + 1) / 2 * 255, (normal_vec->y + 1) / 2 * 255, (normal_vec->z + 1) / 2 * 255, 255);
	return (color.pixel_color);
}


// uint32_t	find_hit_pt(t_object **objects, t_ray *ray)
// {
// 	t_hit_obj	hit_obj;
// 	float		hit_pt;
// 	float		hit_pt_min[2];
// 	int			object_idx;

// 	object_idx = 0;
// 	hit_pt_min[0] = 9999.0;
// 	hit_pt = 9999.0;
// 	hit_pt_min[1] = 2.0;
// 	while (objects[object_idx] != NULL)
// 	{
// 		if (objects[object_idx]->obj_name <= LIGHT)
// 		{
// 			object_idx++;
// 			continue ;
// 		}
// 		hit_pt = get_hit_pt_ft()[objects[object_idx]->obj_name](objects[object_idx], ray);
// 		if (hit_pt < hit_pt_min[0] && hit_pt >= 1)
// 		{
// 			hit_pt_min[0] = hit_pt;
// 			hit_pt_min[1] = object_idx;
// 		}
// 		object_idx++;
// 	}
// 	if (hit_pt_min[0] >= 1)
// 		return (objects[(int)hit_pt_min[1]]->s_sphere.color.pixel_color);
// 	else
// 		return (0);
// }

t_hit_pt_ft	*get_hit_pt_ft(void)
{
	static const t_hit_pt_ft	hit_pt_func[OBJECT_COUNT] = {\
		[PLANE] = &find_plane_hitpt, \
		[SPHERE] = &find_sphere_hitpt, \
		[CYLINDER] = &find_cylinder_hitpt,
	};

	return ((t_hit_pt_ft *)(hit_pt_func));
}

t_get_normal_ft	*get_normal_vec_ft(void)
{
	static const t_get_normal_ft	normal_vec_func[OBJECT_COUNT] = {\
		[PLANE] = &calc_plane_normal_vec, \
		[SPHERE] = &calc_sphere_normal_vec, \
		[CYLINDER] = &calc_cylinder_normal_vec,
	};
// printf("still aliveeee\n\n");

	return ((t_get_normal_ft *)(normal_vec_func));
}
