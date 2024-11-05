/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:55:05 by daspring          #+#    #+#             */
/*   Updated: 2024/11/05 11:23:15 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include <stdio.h>

#include "../../includes/miniRT.h"
#include "../../includes/objects.h"
#include "../../includes/ray.h"
#include "../../includes/color.h"

void	init_cylinder(t_data *data)
{
	t_object	*cylinder;

	cylinder = malloc(1 * sizeof(t_object));
	cylinder->obj_name = CYLINDER;
	cylinder->identifier = CY;
	cylinder->position = set_tuple(-7, 5, 15, PT);
	cylinder->color = set_color(0.3, 0, 0.5, 2515);
	cylinder->s_cy.axis_vec = set_tuple(0.0, 1.0, 0.0, VEC);
	cylinder->s_cy.axis_vec = *tuple_normalize(&cylinder->s_cy.axis_vec);
	cylinder->s_cy.radius = 2.0;
	cylinder->s_cy.height = 5.0;
	cylinder->material = set_material(0.2, 0.7, 0.7, 50);
	data->objects[6] = cylinder;
	cylinder = malloc(1 * sizeof(t_object));
	cylinder->obj_name = CYLINDER;
	cylinder->identifier = CY;
	cylinder->position = set_tuple(6, -7, 15, PT);
	cylinder->color = set_color(1, 0.4, 0.5, 1);
	cylinder->s_cy.axis_vec = set_tuple(0.0, 1.0, 0.0, VEC);
	cylinder->s_cy.axis_vec = *tuple_normalize(&cylinder->s_cy.axis_vec);
	cylinder->s_cy.radius = 2.0;
	cylinder->s_cy.height = 5.0;
	cylinder->material = set_material(0.2, 0.7, 0.7, 150);
	data->objects[7] = cylinder;
}

t_tuple	*calc_cylinder_normal_vec(t_hit_obj *cy, t_ray *ray)
{
	float	top_t;
	float	bottom_t;

	top_t = pt_is_on_top(ray, cy->obj);
	bottom_t = pt_is_on_bottom(ray, cy->obj);
	if ((top_t - cy->t) < 1E-9 && top_t != -1)
	{
		return (&cy->obj->s_cy.axis_vec);
	}
	else if ((bottom_t - cy->t) < 1E-9 && bottom_t != -1)
	{
		return (tuple_neg(&cy->obj->s_cy.axis_vec));
	}
	return (calc_cylinder_lateral_normal_vec(cy, ray));
}
// printf("alive in calc_cylinder_normal_vec\n");

t_tuple	*calc_cylinder_lateral_normal_vec(t_hit_obj *cy, t_ray *ray)
{
	t_tuple	*long_normal_vec;
	t_tuple	*pos_q_dir_vec;
	t_tuple	*subtrahend;
	float	scale_dir;

	pos_q_dir_vec = direction(&cy->obj->position, ray_at_t(ray, cy->t));
	scale_dir = tuple_dot(&cy->obj->s_cy.axis_vec, pos_q_dir_vec);
	subtrahend = tuple_scale(scale_dir, &cy->obj->s_cy.axis_vec);
	long_normal_vec = tuple_subtr(pos_q_dir_vec, subtrahend);
	return (tuple_scale(1 / cy->obj->s_cy.radius, long_normal_vec));
}
