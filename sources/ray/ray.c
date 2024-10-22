/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:48:25 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/22 13:20:53 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../includes/maths.h"
#include "../../includes/miniRT.h"

#include <stdio.h>

t_ray	*create_ray(size_t x_pixel, size_t y_pixel)
{
	t_data		*data;
	t_ray		*r;
	t_tuple		*pixel_coords;

	data = get_data();
	r = malloc(1 * sizeof(t_ray));
	pixel_coords = tuple_add(\
				&data->objects[CAMERA]->s_camera.s_img_plane.origin, \
				tuple_scale(x_pixel, \
					&data->objects[CAMERA]->s_camera.s_img_plane.delta_x_vec));
	pixel_coords = tuple_add(\
				pixel_coords, \
				tuple_scale(y_pixel, \
					&data->objects[CAMERA]->s_camera.s_img_plane.delta_y_vec));
	r->origin_pt = data->objects[CAMERA]->position;
	r->direction_vec = *direction(&r->origin_pt, pixel_coords);
	return (r);
}

// E + t * d
t_tuple	*ray_at_t(t_ray ray, float t)
{
	return (tuple_add(&ray.origin_pt, tuple_scale(t, &ray.direction_vec)));
}
