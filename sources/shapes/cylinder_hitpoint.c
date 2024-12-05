/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_hitpoint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:05:10 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/05 16:23:34 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../includes/objects.h"
#include "../../includes/ray.h"

static void		calc_temp1(t_cy_help *cy_help);
static void		calc_temp2(t_object *cy, t_cy_help *cy_help, t_ray *ray);

double	find_cylinder_hitpt(t_object *cy, t_ray *ray)
{
	double		lateral_t;
	double		base_t;
	t_cy_help	cy_help;

	lateral_t = find_cylinder_lateral_hitpt(cy, &cy_help, ray);
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

double	find_cylinder_lateral_hitpt(t_object *cy, t_cy_help *cy_help, \
									t_ray *ray)
{
	cy_help->v = ray->direction_vec;
	cy_help->v_a = cy->s_cy.axis_vec;
	cy_help->delta_p = direction2(&cy->position, &ray->origin_pt);
	calc_temp1(cy_help);
	calc_temp2(cy, cy_help, ray);
	cy_help->a = tuple_dot_self(&cy_help->temp1);
	cy_help->b = 2 * tuple_dot(&cy_help->temp1, &cy_help->temp2);
	cy_help->c = tuple_dot_self(&cy_help->temp2) - pow(cy->s_cy.radius, 2);
	cy_help->discr = pow(cy_help->b, 2) - 4 * cy_help->a * cy_help->c;
	if (cy_help->discr < 0)
		return (-1);
	else if (cy_help->discr < 1E-9 && \
			pt_is_between_slabs(-cy_help->b / 2 / cy_help->a, ray, cy))
		return (-cy_help->b / 2 / cy_help->a);
	else
	{
		cy_help->t_1 = (-cy_help->b + sqrt(cy_help->discr)) / 2 / cy_help->a;
		cy_help->t_2 = (-cy_help->b - sqrt(cy_help->discr)) / 2 / cy_help->a;
		if (cy_help->t_2 > 1 && pt_is_between_slabs(cy_help->t_2, ray, cy))
			return (cy_help->t_2);
		else if (pt_is_between_slabs(cy_help->t_1, ray, cy))
			return (cy_help->t_1);
	}
	return (-1);
}

static void	calc_temp1(t_cy_help *cy_help)
{
	t_tuple	temp;

	temp = tuple_scale2(tuple_dot(&cy_help->v, &cy_help->v_a), &cy_help->v_a);
	cy_help->temp1 = tuple_subtr2(&cy_help->v, &temp);
}

static void	calc_temp2(t_object *cy, t_cy_help *cy_help, t_ray *ray)
{
	t_tuple	temp;

	temp = tuple_scale2(tuple_dot(&cy_help->delta_p, &cy_help->v_a), \
									&cy_help->v_a);
	cy_help->delta_p = direction2(&cy->position, &ray->origin_pt);
	cy_help->temp2 = tuple_subtr2(&cy_help->delta_p, &temp);
}

double	find_cylinder_base_hitpt(t_object *cy, t_ray *ray)
{
	double	top_t;
	double	bottom_t;

	top_t = pt_is_on_top(ray, cy);
	bottom_t = pt_is_on_bottom(ray, cy);
	if (top_t < bottom_t && top_t >= 0)
		return (top_t);
	else if (bottom_t >= 0)
		return (bottom_t);
	else
		return (-1);
}
