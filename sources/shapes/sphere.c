/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:45:40 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/22 12:37:50 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include <stdio.h>

#include "../../includes/objects.h"

void	init_sphere(t_data *data)
{
	t_object	*sphere;

	sphere = malloc(1 * sizeof(t_object));
	sphere->obj_name = SPHERE;
	sphere->identifier = SP;
	sphere->position = set_tuple(0, 0, 20, PT);
	sphere->s_sphere.color = set_color(200, 100, 100, 255);
	sphere->s_sphere.diameter = 5.0;
	data->objects[2] = sphere;

}

float	find_sphere_hitpt(t_object *sphere, t_ray *ray)
{
	float	discriminant;
	t_tuple *c_q_vec = direction(&ray->origin_pt, &sphere->position);
	float	a = tuple_dot(&ray->direction_vec, &ray->direction_vec);
	float	b = -2 * tuple_dot(&ray->direction_vec, c_q_vec);
	float	c = tuple_dot(c_q_vec, c_q_vec) - pow(sphere->s_sphere.diameter / 2, 2);

	discriminant = b * b - 4 * a * c;
// printf("discriminant: %f\n", discriminant);

	if (discriminant < 0)
		return (-1);
	else if (discriminant < 1E-9)
		return (-b / 2 / a);
	else
	{
		float t_1 = (-b + sqrt(discriminant)) / 2 / a;
		float t_2 = (-b - sqrt(discriminant)) / 2 / a;
		if (t_2 > 1)
			return (t_2);
		else
			return (t_1);
	}
}
