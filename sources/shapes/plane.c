/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:48:46 by linda             #+#    #+#             */
/*   Updated: 2024/11/07 14:29:26 by llacsivy         ###   ########.fr       */
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
	plane->color = set_color(0, 0, 1, 1);
	plane->s_plane.normal_vec = *tuple_normalize(&(t_tuple){0.0, 0.0, -1.0, \
													VEC});
	plane->material = set_material(0.2, 0.7, 0.7, 100);
	data->objects[2] = plane;
	plane = malloc(1 * sizeof(t_object));
	plane->obj_name = PLANE;
	plane->identifier = PL;
	plane->position = set_tuple(10.0, 0.0, 50.0, PT);
	plane->color = set_color(0, 1, 0, 1);
	plane->s_plane.normal_vec = *tuple_normalize(&(t_tuple){-1.0, 2.0, -3.0, \
													VEC});
	plane->material = set_material(0.2, 0.7, 0.7, 200);
	data->objects[3] = plane;
	plane = malloc(1 * sizeof(t_object));
	plane->obj_name = PLANE;
	plane->identifier = PL;
	plane->position = set_tuple(10.0, 0.0, 50.0, PT);
	plane->color = set_color(1, 0, 0, 1);
	plane->s_plane.normal_vec = *tuple_normalize(&(t_tuple){-1.0, 7.0, -3.0, \
													VEC});
	plane->material = set_material(0.2, 0.7, 0.7, 50);
	data->objects[4] = plane;

	plane = malloc(1 * sizeof(t_object));
	plane->obj_name = PLANE;
	plane->identifier = PL;
	plane->position = set_tuple(17.0, -7.0, 15.0, PT);
	plane->color = set_color(1, 0.5, 0.5, 1);
	plane->s_plane.normal_vec = *tuple_normalize(&(t_tuple){-1.0, 0, 0, \
													VEC});
	plane->material = set_material(0.2, 0.7, 0.7, 50);
	data->objects[9] = plane;
	// cylinder->position = set_tuple(6, -7, 15, PT);
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

t_tuple	*calc_plane_normal_vec(t_hit_obj *hit_obj, t_ray *ray)
{
	return (&hit_obj->obj->s_plane.normal_vec);
}

t_object	*create_plane(t_tuple position, t_color color, t_tuple normal_vec)
{
	t_object	*new_plane;

	new_plane = malloc(1 * sizeof(t_object));
	new_plane->obj_name = PLANE;
	new_plane->identifier = PL;
	new_plane->position = position;
	new_plane->color = color;
	new_plane->s_plane.normal_vec = normal_vec;
	return (new_plane);
}
