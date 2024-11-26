/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_hitpoint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:05:10 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/26 20:29:33 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../includes/objects.h"
#include "../../includes/ray.h"

static void		calc_temp1(t_cy_helper *cy_helper);
static void		calc_temp2(t_object *cy, t_cy_helper *cy_helper, t_ray *ray);

float	find_cylinder_hitpt(t_object *cy, t_ray *ray)
{
	float		lateral_t;
	float		base_t;
	t_cy_helper	cy_helper;

	lateral_t = find_cylinder_lateral_hitpt(cy, &cy_helper, ray);
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

float	find_cylinder_lateral_hitpt(t_object *cy, t_cy_helper *cy_helper, t_ray *ray)
{
	cy_helper->v = &ray->direction_vec;
	cy_helper->v_a = &cy->s_cy.axis_vec;
	cy_helper->delta_p = direction(&cy->position, &ray->origin_pt);
	calc_temp1(cy_helper);
	calc_temp2(cy, cy_helper, ray);
	cy_helper->a = tuple_dot_self(cy_helper->temp1);
	cy_helper->b = 2 * tuple_dot(cy_helper->temp1, cy_helper->temp2);
	cy_helper->c = tuple_dot_self(cy_helper->temp2) - pow(cy->s_cy.radius, 2);
	cy_helper->discr = pow(cy_helper->b, 2) - 4 * cy_helper->a * cy_helper->c;
	if (cy_helper->discr < 0)
		return (-1);
	else if (cy_helper->discr < 1E-9 && \
			pt_is_between_slabs(-cy_helper->b / 2 / cy_helper->a, ray, cy))
		return (-cy_helper->b / 2 / cy_helper->a);
	else
	{
		cy_helper->t_1 = (-cy_helper->b + sqrt(cy_helper->discr)) / 2 / cy_helper->a;
		cy_helper->t_2 = (-cy_helper->b - sqrt(cy_helper->discr)) / 2 / cy_helper->a;
		if (cy_helper->t_2 > 1 && pt_is_between_slabs(cy_helper->t_2, ray, cy))
			return (cy_helper->t_2);
		else if (pt_is_between_slabs(cy_helper->t_1, ray, cy))
			return (cy_helper->t_1);
	}
	return (-1);
}

static void	calc_temp1(t_cy_helper *cy_helper)
{
	cy_helper->temp1 = tuple_subtr(cy_helper->v, \
		tuple_scale(tuple_dot(cy_helper->v, cy_helper->v_a), cy_helper->v_a));
}

static void	calc_temp2(t_object *cy, t_cy_helper *cy_helper, t_ray *ray)
{
	cy_helper->delta_p = direction(&cy->position, &ray->origin_pt);
	cy_helper->temp2 = tuple_subtr(cy_helper->delta_p, \
		tuple_scale(tuple_dot(cy_helper->delta_p, cy_helper->v_a), cy_helper->v_a));
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
