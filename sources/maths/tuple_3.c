/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:07:41 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/29 17:50:44 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../../includes/maths.h"

double	tuple_dot(t_tuple *a, t_tuple *b)
{
	if (a->w == 1 && b->w == 1)
	{
		printf("tried to calculate the dot product of a point\n");
		return (nan(""));
	}
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

double	tuple_dot_self(t_tuple *a)
{
	return (tuple_dot(a, a));
}

/*
	using the right hand rule
*/
t_tuple	tuple_cross2(t_tuple *a, t_tuple *b)
{
	t_tuple	c;

	if (a->w == 1 || b->w == 1)
	{
		printf("tried to calculate the cross product of a point\n");
	}
	c.x = a->y * b->z - a->z * b->y;
	c.y = a->z * b->x - a->x * b->z;
	c.z = a->x * b->y - a->y * b->x;
	c.w = 0;
	return (c);
}
