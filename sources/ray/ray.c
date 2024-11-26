/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:48:25 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/26 13:57:08 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../includes/maths.h"
#include "../../includes/miniRT.h"

#include <stdio.h>

t_ray	create_ray(size_t x_pixel, size_t y_pixel)
{
	t_data		*data;
	t_ray		ray;
	t_tuple		*pixel_coords;
	int			idx;

	data = get_data();
	idx = get_object_index(data, C);
	// ray = malloc(1 * sizeof(t_ray));
	pixel_coords = tuple_add(\
				&data->objects[idx]->s_camera.s_img_plane.origin, \
				tuple_scale(x_pixel, \
					&data->objects[idx]->s_camera.s_img_plane.delta_x_vec));
	pixel_coords = tuple_add(\
				pixel_coords, \
				tuple_scale(y_pixel, \
					&data->objects[idx]->s_camera.s_img_plane.delta_y_vec));
	ray.origin_pt = data->objects[idx]->position;
	ray.direction_vec = *direction(&ray.origin_pt, pixel_coords);
	return (ray);
}

// E + t * d
t_tuple	ray_at_t(t_ray *ray, float t)
{
	t_tuple	pt;
	t_tuple	temp;

	temp = tuple_scale2(t, &ray->direction_vec);
	pt = tuple_add2(&ray->origin_pt, &temp);
	return (pt);
}
