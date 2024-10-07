/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:07:41 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/10 20:29:13 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

#include "../../includes/maths.h"

float	tuple_dot(t_tuple a, t_tuple b)
{
	if (a.w == 1 || b.w == 1)
	{
		printf("tried to calculate the dot product of a point");
		return (nan(NULL));
	}
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

/*
	using the right hand rule
*/
t_tuple	tuple_cross(t_tuple a, t_tuple b)
{
	t_tuple	c;

	if (a.w == 1 || b.w == 1)
	{
		printf("tried to calculate the cross product of a point");
		return ((t_tuple){0, 0, 0, 0});
	}
	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	c.w = 0;
	return (c);
}
