/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:31:47 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/05 14:16:28 by daspring         ###   ########.fr       */
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
			mlx_put_pixel(data->image, x_pixel, y_pixel, \
							calc_normal_color(hit_obj, ray));
			mlx_put_pixel(data->image, x_pixel, y_pixel, \
							calc_pixel_color(hit_obj, ray, data));
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

	object_idx = 0;
	hit_obj = malloc(1 * sizeof(t_hit_obj));
	hit_obj->t = 9999.0;
	while (objects[object_idx++] != NULL)
	{
		if (objects[object_idx - 1]->obj_name <= LIGHT)
			continue ;
		hit_pt = get_hit_pt_ft()[objects[object_idx - 1]->obj_name] \
								(objects[object_idx - 1], ray);
		if (hit_pt < hit_obj->t && hit_pt >= 1)
		{
			hit_obj->t = hit_pt;
			hit_obj->obj = objects[object_idx - 1];
		}
	}
	if (hit_obj->t >= 1)
		return (hit_obj);
	else
		return (NULL);
}
// printf("hit_pt: %f\n", hit_pt);
// printf("hit_obj->pt: %f\n", hit_obj->pt);
// printf("hit_obj->pt: %f\n\n\n", hit_obj->pt);
// printf("hit_obj->pt >= 1\n");
		// return (objects[(int)hit_pt_min[1]]->s_sphere.color.pixel_color);
// printf("hit_obj->pt < 1\n");

uint32_t	calc_normal_color(t_hit_obj *hit_obj, t_ray *ray)
{
	t_tuple	*normal_vec;
	t_color	color;

	if (hit_obj == NULL)
		return (2345678);
	normal_vec = get_normal_vec_ft()[hit_obj->obj->obj_name](hit_obj, ray);
	color = set_color((normal_vec->x + 1) / 2, \
			(normal_vec->y + 1) / 2, (normal_vec->z + 1) / 2, 1);
	convert_pixel_colors(&color);
	return (color.pixel_color);
}

uint32_t	calc_pixel_color(t_hit_obj *hit_obj, t_ray *ray, t_data *data)
{
	t_tuple	*normal_vec;
	t_color	color;

	if (hit_obj == NULL)
		return (2345678);
	// normal_vec = get_normal_vec_ft()[hit_obj->obj->obj_name](hit_obj, ray);
	// color = set_color((normal_vec->x + 1) / 2 * 255, \
	// 		(normal_vec->y + 1) / 2 * 255, (normal_vec->z + 1) / 2 * 255, 255);
	color = lighting(hit_obj, data->objects[8], ray);
	convert_pixel_colors(&color);
	return (color.pixel_color);
}

t_hit_pt_ft_array	*get_hit_pt_ft(void)
{
	static const t_hit_pt_ft_array	hit_pt_func_array[OBJECT_COUNT] = {\
		[PLANE] = &find_plane_hitpt, \
		[SPHERE] = &find_sphere_hitpt, \
		[CYLINDER] = &find_cylinder_hitpt,
	};

	return ((t_hit_pt_ft_array *)(hit_pt_func_array));
}

t_get_normal_ft_array	*get_normal_vec_ft(void)
{
	static const t_get_normal_ft_array	normal_vec_func[OBJECT_COUNT] = {\
		[PLANE] = &calc_plane_normal_vec, \
		[SPHERE] = &calc_sphere_normal_vec, \
		[CYLINDER] = &calc_cylinder_normal_vec,
	};

	return ((t_get_normal_ft_array *)(normal_vec_func));
}
