/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/12/05 13:40:35 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../includes/miniRT.h"
#include "../../includes/free.h"

void	fill_canvas(size_t width, size_t height)
{
	int32_t			y_pixel;
	int32_t			x_pixel;
	t_ray			ray;
	t_data			*data;
	t_hit_obj		hit_obj;

	(void)height;
	(void)width;
	data = get_data();
	y_pixel = 0;
	// while (y_pixel < height)
	while (y_pixel < data->mlx->height)
	{
		x_pixel = 0;
		// while (x_pixel < width)
		while (x_pixel < data->mlx->width)
		{
			ray = create_ray(x_pixel, y_pixel);
			hit_obj = find_hit_pt(data->objects, &ray);
if (hit_obj.obj_found == true)
{
	prepare_color_calc(&hit_obj, &ray);
}
			mlx_put_pixel(data->image, x_pixel, y_pixel,
							calc_normal_color(&hit_obj, &ray));
			// mlx_put_pixel(data->image, x_pixel, y_pixel, \
							// calc_pixel_color(&hit_obj, &ray, data));
			x_pixel++;
		}
		y_pixel++;
	}
}

t_hit_obj	find_hit_pt(t_object **objects, t_ray *ray)
{
	t_hit_obj	hit_obj;
	double		hit_t;
	int			object_idx;

hit_t = 0.0;
	// hit_obj.t = INT8_MAX;
	hit_obj.t = INT32_MAX;
	object_idx = 0;
	while (objects[object_idx++] != NULL)
	{
		if (objects[object_idx - 1]->obj_name <= LIGHT)
			continue ;
		hit_t = get_hit_pt_ft()[objects[object_idx - 1]->obj_name] \
								(objects[object_idx - 1], ray);
// if (ray->direction_vec.x == 0 && ray->direction_vec.y == 0)
// {
// 	printf("hitpoints for ray_dir(x = 0, y = 0): %f\n", hit_t);
// }
// if (fabs(ray->direction_vec.y) < 1E-2)
// {
// 	printf("hitpoints for ray_dir(y = 0): %f\n", hit_t);
// }
		if (hit_t < hit_obj.t && hit_t >= 1)
		{
			hit_obj.t = hit_t;
			hit_obj.obj = objects[object_idx - 1];
			hit_obj.hit_pt = ray_at_t(ray, hit_obj.t);
		}
	}
	// if (hit_obj.t >= 1 && hit_obj.t != INT8_MAX)
	if (hit_obj.t >= 1 && hit_obj.t != INT32_MAX)
		hit_obj.obj_found = true;
	else
		hit_obj.obj_found = false;
	return (hit_obj);
}

uint32_t	calc_normal_color(t_hit_obj *hit_obj, t_ray *ray)
{
	// t_tuple	normal_vec;
	t_color	color;

	(void)ray;
	color = set_color(0, 0, 0, 1);
	if (hit_obj->obj_found == true)
	{
		// normal_vec = get_normal_vec_ft()[hit_obj->obj->obj_name](hit_obj, ray);
		color = set_color((hit_obj->normal_vec.x + 1) / 2, \
			(hit_obj->normal_vec.y + 1) / 2, (hit_obj->normal_vec.z + 1) / 2, 1);
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

	light_idx = get_object_index(data, L);
	color = set_color(0, 0, 0, 1);
	// temp = tuple_scale2(1, &ray->direction_vec);
	// temp1 = tuple_normalize2(&ray->direction_vec)
	// temp1 = set_tuple(1,0,0,0);
	temp1 = ray->direction_vec;
	// temp1 = tuple_normalize2(&temp1);
	temp2 = hit_obj->normal_vec;
	// temp2 = tuple_normalize2(&hit_obj->normal_vec);
// 	if (tuple_dot(&temp1, &temp2) > 0 && hit_obj->obj_found == true)
// 	{
// printf("tuple_normalize2(&ray->direction_vec):\n");
// print_tuple(temp1);
// printf("tuple_normalize2(&hit_obj->normal_vec):\n");
// print_tuple(temp2);
// printf("tuple_dot(&temp1, &temp2): %f\n", tuple_dot(&temp1, &temp2));
// printf("\n");
// 	}
	// if (tuple_dot(&temp, &hit_obj->normal_vec) < 0 && tuple_dot(&temp, &hit_obj->normal_vec) > -1 && hit_obj->obj_found == true)
	if (tuple_dot(&temp1, &temp2) < 0 && hit_obj->obj_found == true)
	// if (hit_obj->obj_found == true)
	{
		is_in_shadow(data->objects[light_idx], hit_obj);
		// prepare_color_calc(hit_obj, ray);
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
