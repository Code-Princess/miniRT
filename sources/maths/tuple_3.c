/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:07:41 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/23 15:55:39 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../../includes/maths.h"

float	tuple_dot(t_tuple *a, t_tuple *b)
{
	if (a->w == 1 && b->w == 1)
	{
		printf("tried to calculate the dot product of a point\n");
		return (nan(""));
	}
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

float	tuple_dot_self(t_tuple *a)
{
	return (tuple_dot(a, a));
}

/*
	using the right hand rule
*/
t_tuple	*tuple_cross(t_tuple *a, t_tuple *b)
{
	t_tuple	*c;

	c = malloc(1 * sizeof(t_tuple));
	if (a->w == 1 || b->w == 1)
	{
		printf("tried to calculate the cross product of a point\n");
		return (&(t_tuple){0, 0, 0, 0});
	}
	c->x = a->y * b->z - a->z * b->y;
	c->y = a->z * b->x - a->x * b->z;
	c->z = a->x * b->y - a->y * b->x;
	c->w = 0;
	return (c);
}
