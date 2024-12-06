/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:54:04 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/06 13:41:23 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include <stdio.h>

#include "../../includes/miniRT.h"
#include "../../includes/objects.h"
#include "../../includes/ray.h"
#include "../../includes/color.h"

t_tuple	calc_cylinder_normal_vec(t_hit_obj *cy, t_ray *ray)
{
	double	top_t;
	double	bottom_t;

	top_t = pt_is_on_top(ray, cy->obj);
	bottom_t = pt_is_on_bottom(ray, cy->obj);
	if ((top_t - cy->t) < INFINI_FLOAT && top_t != -1)
	{
		return (cy->obj->s_cy.axis_vec);
	}
	else if ((bottom_t - cy->t) < INFINI_FLOAT && bottom_t != -1)
	{
		return (tuple_neg(&cy->obj->s_cy.axis_vec));
	}
	return (calc_cylinder_lateral_normal_vec(cy, ray));
}

t_tuple	calc_cylinder_lateral_normal_vec(t_hit_obj *cy, t_ray *ray)
{
	t_tuple	long_normal_vec;
	t_tuple	pos_q_dir_vec;
	t_tuple	subtrahend;
	double	scale_dir;
	t_tuple	pt;

	pt = ray_at_t(ray, cy->t);
	pos_q_dir_vec = direction(&cy->obj->position, &pt);
	scale_dir = tuple_dot(&cy->obj->s_cy.axis_vec, &pos_q_dir_vec);
	subtrahend = tuple_scale(scale_dir, &cy->obj->s_cy.axis_vec);
	long_normal_vec = tuple_subtr(&pos_q_dir_vec, &subtrahend);
	return (tuple_scale(1 / cy->obj->s_cy.radius, &long_normal_vec));
}
