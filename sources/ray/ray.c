/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:48:25 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/18 13:21:01 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../includes/maths.h"
#include "../../includes/miniRT.h"

t_ray	*create_ray(size_t x_pixel, size_t y_pixel)
// t_ray	create_ray(t_tuple E, t_tuple P)
{
	t_data		*data;
	t_ray		*r;
	t_tuple		*pixel_coords;

	data = get_data();
	r = malloc(1 * sizeof(t_tuple));
	pixel_coords = tuple_add(&data->objects[CAMERA].s_camera.s_img_plane.origin, tuple_scale(x_pixel, &data->objects[CAMERA].s_camera.s_img_plane.delta_x_vec));
// print_tuple(data->objects[CAMERA].s_camera.s_img_plane.origin);
// print_tuple((data->objects[CAMERA].s_camera.s_img_plane.delta_x_vec));
	pixel_coords = tuple_add(pixel_coords, tuple_scale(y_pixel, &data->objects[CAMERA].s_camera.s_img_plane.delta_y_vec));
// print_tuple(*pixel_coords);
	r->eye_point = data->objects[CAMERA].position;
	r->direction_vec = *direction(&r->eye_point, pixel_coords);
	return (r);
}

// E + t * d
t_tuple	*ray_at_t(t_ray ray, float t)
{
	return (tuple_add(&ray.eye_point, tuple_scale(t, &ray.direction_vec)));
}
