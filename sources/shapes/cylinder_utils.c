/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:54:48 by daspring          #+#    #+#             */
/*   Updated: 2024/12/11 21:13:44 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../includes/objects.h"
#include "../../includes/ray.h"

static bool	pt_is_on_disk(t_tuple disk_center, t_object cylinder, \
							t_tuple hit_pt);

bool	pt_is_between_slabs(double t, t_ray *ray, t_object *cylinder)
{
	t_tuple	q;
	t_tuple	temp1;
	t_tuple	temp2;
	t_tuple	temp3;

	q = ray_at_t(ray, t);
	temp3 = tuple_scale(cylinder->s_cy.height, &cylinder->s_cy.axis_vec);
	temp1 = tuple_add(&cylinder->position, &temp3);
	temp2 = direction(&temp1, &q);
	temp1 = direction(&cylinder->position, &q);
	if (tuple_dot(&cylinder->s_cy.axis_vec, &temp1) > 0 \
		&& tuple_dot(&cylinder->s_cy.axis_vec, &temp2) < 0)
		return (1);
	else
		return (0);
}


#include <stdio.h>

double	pt_is_on_bottom(t_ray *ray, t_object *cylinder)
{
	// t_tuple		pos_q_dir;
	double		t;
	t_object	bottom_plane;
	t_tuple		hit_pt;
	t_tuple		temp;

	temp = tuple_neg(&cylinder->s_cy.axis_vec);
	bottom_plane = create_plane(cylinder->position, \
								set_color(0, 0, 0, 0), temp);
	t = find_plane_hitpt(&bottom_plane, ray);
	hit_pt = ray_at_t(ray, t);
	// pos_q_dir = direction(&cylinder->position, &hit_pt);
	if (pt_is_on_disk(cylinder->position, *cylinder, hit_pt))
	{
// printf("pt_is_on_bottom\n");
		return (t);
	}
	else
		return (-1);
}

double	pt_is_on_top(t_ray *ray, t_object *cylinder)
{
	t_tuple		p_top;
	t_object	top_plane;
	double		t;
	t_tuple		hit_pt;
	t_tuple		temp;

	temp = tuple_scale(cylinder->s_cy.height, &cylinder->s_cy.axis_vec);
	p_top = tuple_add(&cylinder->position, &temp);
	top_plane = create_plane(p_top, set_color(0, 0, 0, 0), \
								cylinder->s_cy.axis_vec);
	t = find_plane_hitpt(&top_plane, ray);
	hit_pt = ray_at_t(ray, t);
	if (pt_is_on_disk(p_top, *cylinder, hit_pt))
	{
// printf("pt_is_on_top\n");
		return (t);
	}
	else
		return (-1);
}

static bool	pt_is_on_disk(t_tuple disk_center, t_object cylinder, \
							t_tuple hit_pt)
{
	t_tuple		p_top_q_dir;
	double		va_dot_p_top_q_dir;

	p_top_q_dir = direction(&disk_center, &hit_pt);
	va_dot_p_top_q_dir = tuple_dot(&cylinder.s_cy.axis_vec, &p_top_q_dir);
	return (tuple_dot_self(&p_top_q_dir) < pow(cylinder.s_cy.radius, 2) && \
		va_dot_p_top_q_dir < INFINI_FLOAT);
}
