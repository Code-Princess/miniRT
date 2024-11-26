/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/11/26 20:14:18 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../includes/miniRT.h"
#include "../../includes/free.h"

void	fill_canvas(size_t width, size_t height)
{
	size_t			y_pixel;
	size_t			x_pixel;
	t_ray			ray;
	t_ray			ray;
	t_data			*data;
	t_hit_obj		hit_obj;

	data = get_data();
	y_pixel = 0;
	while (y_pixel < height)
	{
		x_pixel = 0;
		while (x_pixel < width)
		{
			ray = create_ray(x_pixel, y_pixel);
			hit_obj = find_hit_pt(data->objects, &ray);
			hit_obj = find_hit_pt(data->objects, &ray);
			// mlx_put_pixel(data->image, x_pixel, y_pixel,
			// 				calc_normal_color(hit_obj, ray));
			mlx_put_pixel(data->image, x_pixel, y_pixel, \
							calc_pixel_color(&hit_obj, &ray, data));
			x_pixel++;
		}
		y_pixel++;
	}
}

t_hit_obj	find_hit_pt(t_object **objects, t_ray *ray)
{
	t_hit_obj	hit_obj;
	float		hit_t;
	int			object_idx;

	hit_obj.t = INT8_MAX;
	object_idx = 0;
	while (objects[object_idx++] != NULL)
	{
		if (objects[object_idx - 1]->obj_name <= LIGHT)
			continue ;
		hit_t = get_hit_pt_ft()[objects[object_idx - 1]->obj_name] \
								(objects[object_idx - 1], ray);
		if (hit_t < hit_obj.t && hit_t >= 1)
		{
			hit_obj.t = hit_t;
			hit_obj.obj = objects[object_idx - 1];
			hit_obj.hit_pt = ray_at_t(ray, hit_obj.t);
		}
	}
	if (hit_obj.t >= 1 && hit_obj.t != INT8_MAX)
		hit_obj.obj_found = true;
	else
		hit_obj.obj_found = false;
	return (hit_obj);
}

uint32_t	calc_normal_color(t_hit_obj *hit_obj, t_ray *ray)
{
	t_tuple	normal_vec;
	t_color	color;

	if (hit_obj == NULL)
		color = set_color(0, 0, 0, 1);
	else
	{
		normal_vec = get_normal_vec_ft()[hit_obj->obj->obj_name](hit_obj, ray);
		color = set_color((normal_vec.x + 1) / 2, \
			(normal_vec.y + 1) / 2, (normal_vec.z + 1) / 2, 1);
	}
	convert_pixel_colors(&color);
	return (color.pixel_color);
}

uint32_t	calc_pixel_color(t_hit_obj *hit_obj, t_ray *ray, t_data *data)
{
	t_color		color;
	int			light_idx;

	light_idx = get_object_index(data, L);
	color = set_color(0, 0, 0, 1);
	if (hit_obj->obj_found == true)
	{
		is_in_shadow(data->objects[light_idx], hit_obj);
		prepare_color_calc(hit_obj, ray);
		color = calc_ambient_color(hit_obj, data->objects[light_idx]);
		if (hit_obj->not_in_shadow)
		{
			color = color_add(color, calc_diffuse_color(hit_obj, \
										data->objects[light_idx]));
			color = color_add(color, calc_specular_color(hit_obj, \
										data->objects[light_idx], ray));
		}
	}
	convert_pixel_colors(&color);
	return (color.pixel_color);
}
// printf("didn't hit object\n");

int	get_light_index(t_data *data)
{
	int	idx;

	idx = 0;
	while (data->objects[idx] != NULL)
	{
		if (data->objects[idx]->identifier == L)
			break ;
		idx++;
	}
	return (idx);
}

int	get_object_index(t_data *data, t_identifier identifier)
{
	int	idx;

	idx = 0;
	while (data->objects[idx] != NULL)
	{
		if (data->objects[idx]->identifier == identifier)
			break ;
		idx++;
	}
	return (idx);
}
