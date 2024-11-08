/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:45:40 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/08 10:52:22 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include <stdio.h>

#include "../../includes/objects.h"
#include "../../includes/color.h"

static float	calc_discriminant(t_object *sphere, t_ray *ray, \
									float a, float b);

void	init_sphere(t_data *data)
{
	t_object	*sphere;

	sphere = malloc(1 * sizeof(t_object));
	sphere->obj_name = SPHERE;
	sphere->identifier = SP;
	sphere->position = set_tuple(0, -10, 15, PT);
	sphere->color = set_color(0.8, 0, 0.8, 1);
	sphere->s_sphere.radius = 5.0;
	sphere->material = set_material(0.2, 0.7, 0.7, 100);
	data->objects[5] = sphere;
}

float	find_sphere_hitpt(t_object *sphere, t_ray *ray)
{
	float	discriminant;
	float	a;
	float	b;
	float	t_1;
	float	t_2;

	a = tuple_dot(&ray->direction_vec, &ray->direction_vec);
	b = -2 * tuple_dot(&ray->direction_vec, \
					direction(&ray->origin_pt, &sphere->position));
	discriminant = calc_discriminant(sphere, ray, a, b);
	if (discriminant < 0)
		return (-1);
	else if (discriminant < 1E-9)
		return (-b / 2 / a);
	else
	{
		t_1 = (-b + sqrt(discriminant)) / 2 / a;
		t_2 = (-b - sqrt(discriminant)) / 2 / a;
		if (t_2 > 0)
			return (t_2);
		else
			return (t_1);
	}
}

static float	calc_discriminant(t_object *sphere, t_ray *ray, \
									float a, float b)
{
	float	discriminant;
	t_tuple	*c_q_vec;
	float	c;

	c_q_vec = direction(&ray->origin_pt, &sphere->position);
	c = tuple_dot(c_q_vec, c_q_vec) - pow(sphere->s_sphere.radius, 2);
	discriminant = b * b - 4 * a * c;
	return (discriminant);
}

t_tuple	*calc_sphere_normal_vec(t_hit_obj *hit_obj, t_ray *ray)
{
	t_tuple	*dir_vec;
	t_tuple	*normal_vec;

	dir_vec = direction(&hit_obj->obj->position, ray_at_t(ray, hit_obj->t));
	normal_vec = tuple_scale(1 / hit_obj->obj->s_sphere.radius, dir_vec);
	return (normal_vec);
}
// printf("still alive!\n");
