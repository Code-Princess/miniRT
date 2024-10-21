/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:45:40 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/21 18:02:38 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	sphere->s_sphere.diameter = 100.0;
	data->objects[2] = sphere;

}


float	find_sphere_hitpt(t_object *sphere, t_ray *ray)
{
	float 		discriminant;
	float		l_dot_l;
	float		l_dot_d;
	t_tuple		ray_origin_to_sphere_pos;
	float		t_1;
	float		t_2;

	ray_origin_to_sphere_pos = *direction(&ray->origin_pt, &sphere->position);
// printf("still alive\n");
	l_dot_d = tuple_dot(&ray_origin_to_sphere_pos, &ray->direction_vec);
	l_dot_l = tuple_dot(&ray_origin_to_sphere_pos, &ray_origin_to_sphere_pos);

	discriminant = l_dot_d * l_dot_d - l_dot_l + sphere->s_sphere.diameter * sphere->s_sphere.diameter / 4;

	if (discriminant < 0)
		return (-1);
	else if (discriminant < 1E-9)
		return (-l_dot_d);
	else
	{
		t_1 = -l_dot_d + discriminant;
		t_2 = -l_dot_d - discriminant;
		if (t_2 > 1)
			return (t_2);
		else
			return (t_1);
	}
}