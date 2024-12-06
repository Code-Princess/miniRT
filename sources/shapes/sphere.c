/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:45:40 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/06 13:41:23 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include <stdio.h>

#include "../../includes/objects.h"
#include "../../includes/color.h"

static double	calc_discriminant(t_object *sphere, t_ray *ray, \
									double a, double b);

double	find_sphere_hitpt(t_object *sphere, t_ray *ray)
{
	double	discriminant;
	double	a;
	double	b;
	double	t_2;
	t_tuple	temp;

	temp = direction(&ray->origin_pt, &sphere->position);
	a = tuple_dot(&ray->direction_vec, &ray->direction_vec);
	b = -2 * tuple_dot(&ray->direction_vec, &temp);
	discriminant = calc_discriminant(sphere, ray, a, b);
	if (discriminant < 0)
		return (-1);
	else if (discriminant < 1E-9)
		return (-b / 2 / a);
	else
	{
		t_2 = (-b - sqrt(discriminant)) / 2 / a;
		if (t_2 > 0)
			return (t_2);
		else
			return ((-b + sqrt(discriminant)) / 2 / a);
	}
}

static double	calc_discriminant(t_object *sphere, t_ray *ray, \
									double a, double b)
{
	double	discriminant;
	t_tuple	c_q_vec;
	double	c;

	c_q_vec = direction(&ray->origin_pt, &sphere->position);
	c = tuple_dot_self(&c_q_vec) - pow(sphere->s_sphere.radius, 2);
	discriminant = b * b - 4 * a * c;
	return (discriminant);
}

t_tuple	calc_sphere_normal_vec(t_hit_obj *hit_obj, t_ray *ray)
{
	t_tuple	dir_vec;
	t_tuple	normal_vec;
	t_tuple	pt;

	pt = ray_at_t(ray, hit_obj->t);
	dir_vec = direction(&hit_obj->obj->position, &pt);
	normal_vec = tuple_scale(1 / hit_obj->obj->s_sphere.radius, &dir_vec);
	return (normal_vec);
}
