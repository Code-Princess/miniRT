/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:31:47 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/28 14:02:59 by llacsivy         ###   ########.fr       */
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

	data = get_data();
	y_pixel = 0;
	while (y_pixel < height)
	{
		x_pixel = 0;
		while (x_pixel < width)
		{
			ray = create_ray(x_pixel, y_pixel);
			mlx_put_pixel(data->image, x_pixel, y_pixel, \
							find_hit_pt(data->objects, ray));
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
	hit_obj->pt = 9999.0;
	// hit_pt = 9999.0;
	// hit_pt_min[1] = 2.0;
	hit_obj = malloc(1 * sizeof(t_hit_obj));
	while (objects[object_idx] != NULL)
	{
		if (objects[object_idx]->obj_name <= LIGHT)
		{
			object_idx++;
			continue ;
		}
		hit_pt = get_hit_pt_ft()[objects[object_idx]->obj_name](objects[object_idx], ray);
		if (hit_pt < hit_obj->pt && hit_pt >= 1)
		{
			hit_obj->pt = hit_pt;
			hit_obj->obj = objects[object_idx];
		}
		object_idx++;
	}
	if (hit_obj->pt >= 1)
		return (hit_obj);
		// return (objects[(int)hit_pt_min[1]]->s_sphere.color.pixel_color);
	else
		return (NULL);
}

uint32_t	calc_pixel_color(t_hit_obj *hit_obj)
{
	return (0);
}


// uint32_t	calc_pixel_color(t_hit_obj *hit_obj)

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
		[SPHERE] = &calc_sphere_normal_vec,
	};
	
	return ((t_get_normal_ft *)(normal_vec_func));
}
