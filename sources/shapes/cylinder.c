/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:55:05 by daspring          #+#    #+#             */
/*   Updated: 2024/10/24 16:02:04 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include <stdio.h>

#include "../../includes/miniRT.h"
#include "../../includes/objects.h"
#include "../../includes/ray.h"

static float	calc_discriminant_cy(t_object *sphere, t_ray *ray, \
									float a, float b);
static int		pt_is_between_slabs(float t, t_ray *ray, t_object *cylinder);

void	init_cylinder(t_data *data)
{
	t_object	*cylinder;

	cylinder = malloc(1 * sizeof(t_object));
	cylinder->obj_name = CYLINDER;
	cylinder->identifier = CY;
	cylinder->position = set_tuple(0, -5, 18, PT);
	cylinder->s_cy.color = set_color(100, 0, 150, 255);
	cylinder->s_cy.axis_vec = set_tuple(0.0, 1.0, 0, VEC);
	cylinder->s_cy.axis_vec = *tuple_normalize(&cylinder->s_cy.axis_vec);
	cylinder->s_cy.diameter = 5.0;
	cylinder->s_cy.height = 15.0;
	data->objects[6] = cylinder;
}

float	find_cylinder_hitpt(t_object *cy, t_ray *ray)
{
	cy->s_cy.v = &ray->direction_vec;
	cy->s_cy.v_a = &cy->s_cy.axis_vec;
	cy->s_cy.delta_p = direction(&cy->position, &ray->origin_pt);
	cy->s_cy.temp1 = tuple_subtr(cy->s_cy.v, tuple_scale(tuple_dot(cy->s_cy.v, cy->s_cy.v_a), cy->s_cy.v_a));
	cy->s_cy.temp2 = tuple_subtr(cy->s_cy.delta_p, tuple_scale(tuple_dot(cy->s_cy.delta_p, cy->s_cy.v_a), cy->s_cy.v_a));
	cy->s_cy.a = tuple_dot_self(cy->s_cy.temp1);
	cy->s_cy.b = 2 * tuple_dot(cy->s_cy.temp1, cy->s_cy.temp2);
	cy->s_cy.c = tuple_dot_self(cy->s_cy.temp2) - pow(cy->s_cy.diameter / 2, 2);
	cy->s_cy.discr = pow(cy->s_cy.b, 2) - 4 * cy->s_cy.a * cy->s_cy.c;
	if (cy->s_cy.discr < 0)
		return (-1);
	else if (cy->s_cy.discr < 1E-9 && pt_is_between_slabs(-cy->s_cy.b / 2 / cy->s_cy.a, ray, cy))
		return (-cy->s_cy.b / 2 / cy->s_cy.a);
	else
	{
		cy->s_cy.t_1 = (-cy->s_cy.b + sqrt(cy->s_cy.discr)) / 2 / cy->s_cy.a;
		cy->s_cy.t_2 = (-cy->s_cy.b - sqrt(cy->s_cy.discr)) / 2 / cy->s_cy.a;
		if (cy->s_cy.t_2 > 1 && pt_is_between_slabs(cy->s_cy.t_2, ray, cy))
			return (cy->s_cy.t_2);
		else if (pt_is_between_slabs(cy->s_cy.t_1, ray, cy))
			return (cy->s_cy.t_1);
	}
	return (-1);
}

static float	calc_discriminant_cy(t_object *sphere, t_ray *ray, \
									float a, float b)
{
	float	discriminant;
	float	c;

	c = pow(ray->origin_pt.x, 2) + pow(ray->origin_pt.z, 2) - 1;
	discriminant = b * b - 4 * a * c;
	return (discriminant);
}

static int	pt_is_between_slabs(float t, t_ray *ray, t_object *cylinder)
{
	t_tuple	*q;

	q = ray_at_t(*ray, t);
	if (tuple_dot(&cylinder->s_cy.axis_vec, \
			direction(&cylinder->position, q)) > 0 \
		&& \
		tuple_dot(&cylinder->s_cy.axis_vec, \
					direction(tuple_add(&cylinder->position, \
								tuple_scale(cylinder->s_cy.height, \
									&cylinder->s_cy.axis_vec)), q)) < 0)
		return (1);
	else
		return (0);
}
