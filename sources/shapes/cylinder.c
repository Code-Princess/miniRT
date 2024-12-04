/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/12/04 19:50:47 by daspring         ###   ########.fr       */
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
	t_tuple	temp;

	top_t = pt_is_on_top(ray, cy->obj);
	bottom_t = pt_is_on_bottom(ray, cy->obj);
	if ((top_t - cy->t) < INFINI_FLOAT && top_t != -1)
	{
		return (cy->obj->s_cy.axis_vec);
		// return (tuple_neg2(&cy->obj->s_cy.axis_vec));
		// temp = tuple_neg2(cy->obj->s_cy.axis_vec);
		// return (cy->obj->s_cy.axis_vec);
	}
	else if ((bottom_t - cy->t) < INFINI_FLOAT && bottom_t != -1)
	{
		return (tuple_neg2(&cy->obj->s_cy.axis_vec));
		// return (cy->obj->s_cy.axis_vec);
	}
	return (calc_cylinder_lateral_normal_vec(cy, ray));
}
// printf("alive in calc_cylinder_normal_vec\n");

t_tuple	calc_cylinder_lateral_normal_vec(t_hit_obj *cy, t_ray *ray)
{
	t_tuple	long_normal_vec;
	t_tuple	pos_q_dir_vec;
	t_tuple	subtrahend;
	double	scale_dir;
	t_tuple	pt;

	pt = ray_at_t(ray, cy->t);
	pos_q_dir_vec = direction2(&cy->obj->position, &pt);
	scale_dir = tuple_dot(&cy->obj->s_cy.axis_vec, &pos_q_dir_vec);
	subtrahend = tuple_scale2(scale_dir, &cy->obj->s_cy.axis_vec);
	long_normal_vec = tuple_subtr2(&pos_q_dir_vec, &subtrahend);
	return (tuple_scale2(1 / cy->obj->s_cy.radius, &long_normal_vec));
}
