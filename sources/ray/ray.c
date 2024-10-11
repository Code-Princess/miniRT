/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:48:25 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/11 17:47:50 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/maths.h"
#include "../../includes/miniRT.h"

t_ray	create_ray(t_tuple E, t_tuple P)
{
	t_ray r;

	r.E = E;
	r.d = direction(E, P);
	return (r);
}

// E + t * d
t_tuple	ray_at_t(t_ray ray, float t)
{
	return (tuple_add(ray.E, tuple_scale(t, ray.d)));
}
