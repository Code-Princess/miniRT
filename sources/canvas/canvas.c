/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 12:52:50 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/12 00:18:06 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../includes/miniRT.h"
#include "../../includes/free.h"

void	fill_canvas(t_data *data)
{
	int32_t			y_pixel;
	int32_t			x_pixel;
	t_ray			ray;
	t_hit_obj		hit_obj;

	y_pixel = 0;
	while (y_pixel < data->mlx->height)
	{
		x_pixel = 0;
		while (x_pixel < data->mlx->width)
		{
			if (cam_not_inside(data))
			{
				ray = create_ray(x_pixel, y_pixel);
				hit_obj = find_hit_pt(data->objects, &ray);
				mlx_put_pixel(data->image, x_pixel, y_pixel, \
						calc_pixel_color(&hit_obj, &ray, data));
			}
			else
				mlx_put_pixel(data->image, x_pixel, y_pixel, (uint32_t)255);
			x_pixel++;
		}
		y_pixel++;
	}
}

bool	cam_not_inside(t_data *data)
{
	t_object	*cam;
	int			cam_idx;

	cam_idx = get_object_index(data, C);
	cam = data->objects[cam_idx];
	return (!cam->s_camera.is_inside_obj);
}

t_hit_obj	find_hit_pt(t_object **objects, t_ray *ray)
{
	t_hit_obj	hit_obj;
	double		hit_t;
	int			object_idx;

	hit_t = 0.0;
	hit_obj = (t_hit_obj){.t = INT32_MAX};
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
	if (hit_obj.t >= 1 && hit_obj.t != INT32_MAX)
		hit_obj.obj_found = true;
	return (hit_obj);
}

uint32_t	calc_normal_color(t_hit_obj *hit_obj, t_ray *ray)
{
	t_color	color;

	(void)ray;
	color = set_color(0, 0, 0, 1);
	if (hit_obj->obj_found == true)
	{
		color = set_color((hit_obj->normal_vec.x + 1) / 2, \
			(hit_obj->normal_vec.y + 1) / 2, \
			(hit_obj->normal_vec.z + 1) / 2, 1);
	}
	convert_pixel_colors(&color);
	return (color.pixel_color);
}

uint32_t	calc_pixel_color(t_hit_obj *hit_obj, t_ray *ray, t_data *data)
{
	t_color		color;
	int			light_idx;
	t_tuple		temp1;
	t_tuple		temp2;

	if (hit_obj->obj_found == true)
		prepare_color_calc(hit_obj, ray);
	light_idx = get_object_index(data, L);
	color = set_color(0, 0, 0, 1);
	temp1 = ray->direction_vec;
	temp2 = hit_obj->normal_vec;
	if (tuple_dot(&temp1, &temp2) < 0 && hit_obj->obj_found == true)
	{
		is_in_shadow(data->objects[light_idx], hit_obj);
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
	// {
	// 	color = set_color((hit_obj->normal_vec.x + 1) / 2, 
	// 		(hit_obj->normal_vec.y + 1) / 2, 
	// 		(hit_obj->normal_vec.z + 1) / 2, 1);
	// }
