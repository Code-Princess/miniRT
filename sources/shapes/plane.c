/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:48:46 by linda             #+#    #+#             */
/*   Updated: 2024/10/22 13:18:33 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "../../includes/miniRT.h"
#include "../../includes/objects.h"
#include "../../includes/maths.h"
#include "../../includes/color.h"

void	init_plane(t_data *data)
{
	t_object	*plane;

	plane = malloc(1 * sizeof(t_object));
	plane->obj_name = PLANE;
	plane->identifier = PL;
	plane->position = set_tuple(10.0, 0.0, 50.0, PT);
	plane->s_plane.color = set_color(0, 0, 255, 255);
	plane->s_plane.normal_vec = *tuple_normalize(&(t_tuple){0.0, 0.0, 1.0, \
													VEC});
	data->objects[2] = plane;
	plane = malloc(1 * sizeof(t_object));
	plane->obj_name = PLANE;
	plane->identifier = PL;
	plane->position = set_tuple(10.0, 0.0, 50.0, PT);
	plane->s_plane.color = set_color(0, 150, 0, 255);
	plane->s_plane.normal_vec = *tuple_normalize(&(t_tuple){-1.0, 2.0, -3.0, \
													VEC});
	data->objects[3] = plane;
	plane = malloc(1 * sizeof(t_object));
	plane->obj_name = PLANE;
	plane->identifier = PL;
	plane->position = set_tuple(10.0, 0.0, 50.0, PT);
	plane->s_plane.color = set_color(200, 100, 0, 255);
	plane->s_plane.normal_vec = *tuple_normalize(&(t_tuple){-1.0, 7.0, -3.0, \
													VEC});
	data->objects[4] = plane;
}

float	find_plane_hitpt(t_object *plane, t_ray *ray)
{
	float	t_enumerator;
	float	t_denominator;

	t_enumerator = tuple_dot(&plane->s_plane.normal_vec, \
							tuple_subtr(&plane->position, &ray->origin_pt));
	t_denominator = tuple_dot(&plane->s_plane.normal_vec, &ray->direction_vec);
	return (t_enumerator / t_denominator);
}
