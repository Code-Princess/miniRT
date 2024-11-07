/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:25:29 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/07 15:17:19 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../includes/objects.h"
#include "../../includes/ray.h"

int	pt_is_between_slabs(float t, t_ray *ray, t_object *cylinder)
{
	t_tuple	*q;

	q = ray_at_t(ray, t);
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

float	pt_is_on_bottom(t_ray *ray, t_object *cylinder)
{
	t_tuple		*pos_q_dir;
	float		dist_pos_q_squared;
	float		va_dot_pos_q_dir;
	float		t;
	t_object	*bottom_plane;

	bottom_plane = create_plane(cylinder->position, set_color(0, 0, 0, 0), \
								*tuple_neg(&cylinder->s_cy.axis_vec));
	t = find_plane_hitpt(bottom_plane, ray);
	pos_q_dir = direction(&cylinder->position, ray_at_t(ray, t));
	va_dot_pos_q_dir = tuple_dot(&cylinder->s_cy.axis_vec, pos_q_dir);
	dist_pos_q_squared = tuple_dot_self(pos_q_dir);
	if (dist_pos_q_squared < pow(cylinder->s_cy.radius, 2) && \
			va_dot_pos_q_dir < INFINI_FLOAT)
		return (t);
	else
		return (-1);
}

float	pt_is_on_top(t_ray *ray, t_object *cylinder)
{
	t_tuple		*p_top;
	t_tuple		*p_top_q_dir;
	float		va_dot_p_top_q_dir;
	t_object	*top_plane;
	float		t;

	p_top = tuple_add(&cylinder->position, \
								tuple_scale(cylinder->s_cy.height, \
								&cylinder->s_cy.axis_vec));
	top_plane = create_plane(*p_top, set_color(0, 0, 0, 0), \
								cylinder->s_cy.axis_vec);
	t = find_plane_hitpt(top_plane, ray);
	p_top_q_dir = direction(p_top, ray_at_t(ray, t));
	va_dot_p_top_q_dir = tuple_dot(&cylinder->s_cy.axis_vec, p_top_q_dir);
	if (tuple_dot_self(p_top_q_dir) < pow(cylinder->s_cy.radius, 2) && \
		va_dot_p_top_q_dir < INFINI_FLOAT)
		return (t);
	else
		return (-1);
}
