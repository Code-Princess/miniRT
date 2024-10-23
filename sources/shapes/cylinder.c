/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:55:05 by daspring          #+#    #+#             */
/*   Updated: 2024/10/23 16:05:46 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include <stdio.h>

#include "../../includes/miniRT.h"
#include "../../includes/objects.h"

static float	calc_discriminant_cy(t_object *sphere, t_ray *ray, \
									float a, float b);

void	init_cylinder(t_data *data)
{
	t_object	*cylinder;

	cylinder = malloc(1 * sizeof(t_object));
	cylinder->obj_name = CYLINDER;
	cylinder->identifier = CY;
	cylinder->position = set_tuple(0, 0, 5, PT);
	cylinder->s_cylinder.color = set_color(100, 0, 150, 255);
	cylinder->s_cylinder.axis_vec = set_tuple(1.0, 0.0, 0, VEC);
	cylinder->s_cylinder.diameter = 5.0;
	cylinder->s_cylinder.height = 7.0;
	data->objects[6] = cylinder;
}

float	find_cylinder_hitpt(t_object *cylinder, t_ray *ray)
{
	float	discriminant;
	float	a;
	float	b;
	float	c;
	float	t_1;
	float	t_2;

	t_tuple	*v = &ray->direction_vec;
	t_tuple	*v_a = &cylinder->s_cylinder.axis_vec;
	t_tuple	*delta_p = direction(&cylinder->position, &ray->origin_pt);


	// a = pow(ray->direction_vec.x, 2) + pow(ray->direction_vec.z, 2);
	// b = 2 * ray->origin_pt.x * ray->direction_vec.x + \
	// 	2 * ray->origin_pt.z * ray->direction_vec.z;

	t_tuple		*temp1 = tuple_subtr(v, tuple_scale(tuple_dot(v, v_a), v_a));
	t_tuple		*temp2 = tuple_subtr(delta_p, tuple_scale(tuple_dot(delta_p, v_a), v_a));
print_tuple(*temp1);
	a = tuple_dot_self(temp1);
// printf("cy_a: %f\n", tuple_dot_self(temp1));
	b = 2 * tuple_dot(temp1, temp2);
	c = tuple_dot_self(temp2) - pow(cylinder->s_cylinder.diameter / 2, 2);
	discriminant = b * b - 4 * a * c;


	// discriminant = calc_discriminant_cy(cylinder, ray, a, b);
	if (discriminant < 0)
		return (-1);
	else if (discriminant < 1E-9)
		return (-b / 2 / a);
	else
	{
		t_1 = (-b + sqrt(discriminant)) / 2 / a;
		t_2 = (-b - sqrt(discriminant)) / 2 / a;
printf("cy_t1: %f\n", t_1);
		if (t_2 > 1)
			return (t_2);
		else
			return (t_1);
	}
}

static float	calc_discriminant_cy(t_object *sphere, t_ray *ray, \
									float a, float b)
{
	float	discriminant;
	float	c;

	c = pow(ray->origin_pt.x, 2) + pow(ray->origin_pt.z, 2) - 1;
	discriminant = b * b - 4 * a * c;
	return (discriminant);
}