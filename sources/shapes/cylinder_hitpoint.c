/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_hitpoint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:05:10 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/13 19:41:41 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../includes/objects.h"
#include "../../includes/ray.h"

static void		calc_temp1(t_object *cy);
static void		calc_temp2(t_object *cy, t_ray *ray);

float	find_cylinder_hitpt(t_object *cy, t_ray *ray)
{
	float		lateral_t;
	float		base_t;

	lateral_t = find_cylinder_lateral_hitpt(cy, ray);
	base_t = find_cylinder_base_hitpt(cy, ray);
	if (lateral_t < 0 && base_t < 0)
		return (-1);
	else if (lateral_t < 0)
		return (base_t);
	else if (base_t < 0)
		return (lateral_t);
	else if (lateral_t < base_t)
		return (lateral_t);
	else
		return (base_t);
}

float	find_cylinder_lateral_hitpt(t_object *cy, t_ray *ray)
{
	cy->s_cy.v = &ray->direction_vec;
	cy->s_cy.v_a = &cy->s_cy.axis_vec;
	cy->s_cy.delta_p = direction(&cy->position, &ray->origin_pt);
	calc_temp1(cy);
	calc_temp2(cy, ray);
	cy->s_cy.a = tuple_dot_self(cy->s_cy.temp1);
	cy->s_cy.b = 2 * tuple_dot(cy->s_cy.temp1, cy->s_cy.temp2);
	cy->s_cy.c = tuple_dot_self(cy->s_cy.temp2) - pow(cy->s_cy.radius, 2);
	cy->s_cy.discr = pow(cy->s_cy.b, 2) - 4 * cy->s_cy.a * cy->s_cy.c;
	if (cy->s_cy.discr < 0)
		return (-1);
	else if (cy->s_cy.discr < 1E-9 && \
			pt_is_between_slabs(-cy->s_cy.b / 2 / cy->s_cy.a, ray, cy))
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

static void	calc_temp1(t_object *cy)
{
	cy->s_cy.temp1 = tuple_subtr(cy->s_cy.v, \
		tuple_scale(tuple_dot(cy->s_cy.v, cy->s_cy.v_a), cy->s_cy.v_a));
}

static void	calc_temp2(t_object *cy, t_ray *ray)
{
	cy->s_cy.delta_p = direction(&cy->position, &ray->origin_pt);
	cy->s_cy.temp2 = tuple_subtr(cy->s_cy.delta_p, \
		tuple_scale(tuple_dot(cy->s_cy.delta_p, cy->s_cy.v_a), cy->s_cy.v_a));
}

float	find_cylinder_base_hitpt(t_object *cy, t_ray *ray)
{
	float	top_t;
	float	bottom_t;

	top_t = pt_is_on_top(ray, cy);
	bottom_t = pt_is_on_bottom(ray, cy);
	if (top_t < bottom_t && top_t >= 0)
		return (top_t);
	else if (bottom_t >= 0)
		return (bottom_t);
	else
		return (-1);
}
