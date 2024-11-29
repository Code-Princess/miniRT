/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:48:46 by linda             #+#    #+#             */
/*   Updated: 2024/11/29 15:37:31 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "../../includes/miniRT.h"
#include "../../includes/objects.h"
#include "../../includes/maths.h"
#include "../../includes/color.h"

double	find_plane_hitpt(t_object *plane, t_ray *ray)
{
	double	t_enumerator;
	double	t_denominator;
	t_tuple	temp;

	temp = tuple_subtr2(&plane->position, &ray->origin_pt);
	t_enumerator = tuple_dot2(&plane->s_plane.normal_vec, &temp);
	t_denominator = tuple_dot2(&plane->s_plane.normal_vec, &ray->direction_vec);
	return (t_enumerator / t_denominator);
}

t_tuple	calc_plane_normal_vec(t_hit_obj *hit_obj, t_ray *ray)
{
	(void)ray;
	return (hit_obj->obj->s_plane.normal_vec);
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

t_object	create_plane2(t_tuple position, t_color color, t_tuple normal_vec)
{
	t_object	new_plane;

	new_plane.obj_name = PLANE;
	new_plane.identifier = PL;
	new_plane.position = position;
	new_plane.color = color;
	new_plane.s_plane.normal_vec = normal_vec;
	return (new_plane);
}
