/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:48:25 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/14 21:44:23 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/maths.h"
#include "../../includes/miniRT.h"

t_ray	create_ray(t_tuple E, t_tuple P)
{
	t_ray	r;

	r.eye_point = E;
	r.direction_vec = direction(E, P);
	return (r);
}

// E + t * d
t_tuple	ray_at_t(t_ray ray, float t)
{
	return (tuple_add(ray.eye_point, tuple_scale(t, ray.direction_vec)));
}
