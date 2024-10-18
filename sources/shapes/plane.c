/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:48:46 by linda             #+#    #+#             */
/*   Updated: 2024/10/18 20:49:41 by daspring         ###   ########.fr       */
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
	t_object    *plane;

	plane = malloc(1 * sizeof(t_object));
	plane->obj_name = PLANE;
	plane->identifier = PL;
	plane->position.x = 10.0;
	plane->position.y = 0.0;
	plane->position.z = 50.0;
	plane->position.w = PT;
	plane->s_plane.color.colors[RED] = 0;
	plane->s_plane.color.colors[GREEN] = 0;
	plane->s_plane.color.colors[BLUE] = 255;
	plane->s_plane.color.colors[OPAC] = 255;
	plane->s_plane.normal_vec = *tuple_normalize(&(t_tuple){0.0, 0.0, 1.0, VEC});
	data->objects[2] = plane;
// print_tuple(plane->s_plane.normal_vec);
	
	plane = malloc(1 * sizeof(t_object));
	plane->obj_name = PLANE;
	plane->identifier = PL;
	plane->position.x = 10.0;
	plane->position.y = 0.0;
	plane->position.z = 50.0;
	plane->position.w = PT;
	plane->s_plane.color.colors[RED] = 0;
	plane->s_plane.color.colors[GREEN] = 150;
	plane->s_plane.color.colors[BLUE] = 0;
	plane->s_plane.color.colors[OPAC] = 255;
	plane->s_plane.normal_vec = *tuple_normalize(&(t_tuple){-1.0, 2.0, -3.0, VEC});
	data->objects[3] = plane;
// print_tuple(plane->s_plane.normal_vec);
// print_tuple(data->objects[3].s_plane.normal_vec);
// print_tuple((t_tuple){-1, 0, -1, VEC});
// print_tuple((t_tuple){-1, 0, -1, 0});
}

float	find_plane_hitpt(t_object *plane, t_ray *ray)
{
	float	t_enumerator;
	float	t_denominator;

// print_tuple(plane->s_plane.normal_vec);
// print_tuple(ray->direction_vec);
// print_tuple(*tuple_subtr(&plane->position, &ray->eye_point));

	t_enumerator = tuple_dot(&plane->s_plane.normal_vec, tuple_subtr(&plane->position, &ray->eye_point));
	t_denominator = tuple_dot(&plane->s_plane.normal_vec, &ray->direction_vec);
// printf("t_denominator: %f\n", t_denominator);
	return (t_enumerator / t_denominator);
}
