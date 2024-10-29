/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:55:05 by daspring          #+#    #+#             */
/*   Updated: 2024/10/29 22:55:31 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include <stdio.h>

#include "../../includes/miniRT.h"
#include "../../includes/objects.h"
#include "../../includes/ray.h"

static void		calc_temp1(t_object *cy, t_ray *ray);
static void		calc_temp2(t_object *cy, t_ray *ray);

void	init_cylinder(t_data *data)
{
	t_object	*cylinder;

	cylinder = malloc(1 * sizeof(t_object));
	cylinder->obj_name = CYLINDER;
	cylinder->identifier = CY;
	// cylinder->position = set_tuple(0, -5, 18, PT);
	cylinder->position = set_tuple(-7, -5, 15, PT);
	cylinder->s_cy.color = set_color(100, 0, 150, 255);
	cylinder->s_cy.axis_vec = set_tuple(0.0, 1.0, 1.0, VEC);
	cylinder->s_cy.axis_vec = *tuple_normalize(&cylinder->s_cy.axis_vec);
	cylinder->s_cy.radius = 5.0;
	cylinder->s_cy.height = 15.0;
	cylinder->s_cy.pos_rel_to_camera = BETWEEN;
	if (data->objects[CAMERA]->position.y < cylinder->position.y)
		cylinder->s_cy.pos_rel_to_camera = BELOW;
	else if (data->objects[CAMERA]->position.y > cylinder->position.y)
		cylinder->s_cy.pos_rel_to_camera = ABOVE;
	data->objects[6] = cylinder;
}

float	find_cylinder_hitpt(t_object *cy, t_ray *ray)
{
	float	lateral_t;
	float	base_t;
	t_hit_obj	*hit_obj;

	lateral_t = find_cylinder_lateral_hitpt(cy, ray);
// if (lateral_t > 0)
// printf("lateral_t: %f\n", lateral_t);
	base_t = find_cylinder_base_hitpt(cy, ray);
// if (base_t > 0)
// printf("base_t: %f\n\n\n", base_t);
	// base_t = 5.0;
	if (lateral_t < 1 && base_t < 1)
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
float	find_cylinder_base_hitpt(t_object *cy, t_ray *ray)
{
	float	top_t;
	float	bottom_t;

	top_t = pt_is_on_top(ray, cy);
	bottom_t = pt_is_on_bottom(ray, cy);
	if (top_t < bottom_t && top_t >= 1)
		return (top_t);
	else if (bottom_t >= 1)
		return (bottom_t);
	else
		return (-1);
}

float	find_cylinder_lateral_hitpt(t_object *cy, t_ray *ray)
{
	cy->s_cy.v = &ray->direction_vec;
	cy->s_cy.v_a = &cy->s_cy.axis_vec;
	cy->s_cy.delta_p = direction(&cy->position, &ray->origin_pt);
	calc_temp1(cy, ray);
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

static void	calc_temp1(t_object *cy, t_ray *ray)
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

t_tuple	*calc_cylinder_normal_vec(t_hit_obj *cy, t_ray *ray)
{
	t_tuple	*long_normal_vec;
	t_tuple	*pos_q_dir_vec;
	t_tuple	*subtrahend;
	float	scale_dir;

// printf("cy->obj->s_cy.pos_rel_to_camera: %d\n", cy->obj->s_cy.pos_rel_to_camera);

	// if (cy->obj->s_cy.pos_rel_to_camera == BELOW)
	// {
	// 	t_object	*bottom_plane;
	// 	float		t;

	// 	bottom_plane = create_plane(cy->obj->position, set_color(0,0,0,0), cy->obj->s_cy.axis_vec);
	// 	t = find_plane_hitpt(bottom_plane, ray);
	// 	if (t - cy->t < 1E-9)
	// 	{
	// 		return (tuple_neg(&cy->obj->s_cy.axis_vec));
	// 	}
	// }
	// else if (cy->obj->s_cy.pos_rel_to_camera == ABOVE)
	// {
// 		t_object	*top_plane;
// 		t_tuple 	*p_top;
// 		float		t;

// 		p_top = tuple_add(&cy->obj->position, \
// 								tuple_scale(cy->obj->s_cy.height, &cy->obj->s_cy.axis_vec));
// 		top_plane = create_plane(*p_top, set_color(0,0,0,0), cy->obj->s_cy.axis_vec);
// 		t = find_plane_hitpt(top_plane, ray);
// 		if (t - cy->t < 1)
// 		// if (t - cy->t < 1E-9)
// 		{
// printf("t - cy->t: %f\n", t - cy->t);
// 			return (&cy->obj->s_cy.axis_vec);
// 		}

	// }
// printf("alive in calc_cylinder_normal_vec\n");
		pos_q_dir_vec = direction(&cy->obj->position, ray_at_t(*ray, cy->t));
		scale_dir = tuple_dot(&cy->obj->s_cy.axis_vec, pos_q_dir_vec);
		subtrahend = tuple_scale(scale_dir, &cy->obj->s_cy.axis_vec);
		long_normal_vec = tuple_subtr(pos_q_dir_vec, subtrahend);
		return (tuple_scale(1 / cy->obj->s_cy.radius, long_normal_vec));
}
