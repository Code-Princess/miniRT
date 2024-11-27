/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/11/27 13:51:01 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <math.h>

#include "../../includes/objects.h"
#include "../../includes/ray.h"

int	pt_is_between_slabs(double t, t_ray *ray, t_object *cylinder)
{
	t_tuple	q;
	t_tuple	temp1;
	t_tuple	temp2;
	t_tuple	temp3;

	q = ray_at_t(ray, t);
	temp3 = tuple_scale2(cylinder->s_cy.height, &cylinder->s_cy.axis_vec);
	temp1 = tuple_add2(&cylinder->position, &temp3);
	temp2 = direction2(&temp1, &q);
	temp1 = direction2(&cylinder->position, &q);
	if (tuple_dot(&cylinder->s_cy.axis_vec, &temp1) > 0 \
		&& tuple_dot(&cylinder->s_cy.axis_vec, &temp2) < 0)
		return (1);
	else
		return (0);
}

double	pt_is_on_bottom(t_ray *ray, t_object *cylinder)
{
	t_tuple		pos_q_dir;
	double		dist_pos_q_squared;
	double		va_dot_pos_q_dir;
	double		t;
	t_object	bottom_plane;
	t_tuple		pt;
	t_tuple		temp;

	temp = tuple_neg2(&cylinder->s_cy.axis_vec);
	bottom_plane = create_plane2(cylinder->position, set_color(0, 0, 0, 0), temp);
	t = find_plane_hitpt(&bottom_plane, ray);
	pt = ray_at_t(ray, t);
	pos_q_dir = direction2(&cylinder->position, &pt);
	va_dot_pos_q_dir = tuple_dot(&cylinder->s_cy.axis_vec, &pos_q_dir);
	dist_pos_q_squared = tuple_dot_self(&pos_q_dir);
	if (dist_pos_q_squared < pow(cylinder->s_cy.radius, 2) && \
			va_dot_pos_q_dir < INFINI_FLOAT)
		return (t);
	else
		return (-1);
}

double	pt_is_on_top(t_ray *ray, t_object *cylinder)
{
	t_tuple		p_top;
	t_tuple		p_top_q_dir;
	double		va_dot_p_top_q_dir;
	t_object	top_plane;
	double		t;
	t_tuple		pt;
	t_tuple		temp;

	temp = tuple_scale2(cylinder->s_cy.height, &cylinder->s_cy.axis_vec);
	p_top = tuple_add2(&cylinder->position, &temp);
	top_plane = create_plane2(p_top, set_color(0, 0, 0, 0), \
								cylinder->s_cy.axis_vec);
	t = find_plane_hitpt(&top_plane, ray);
	pt = ray_at_t(ray, t);
	p_top_q_dir = direction2(&p_top, &pt);
	va_dot_p_top_q_dir = tuple_dot(&cylinder->s_cy.axis_vec, &p_top_q_dir);
	if (tuple_dot_self(&p_top_q_dir) < pow(cylinder->s_cy.radius, 2) && \
		va_dot_p_top_q_dir < INFINI_FLOAT)
		return (t);
	else
		return (-1);
}
