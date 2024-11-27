/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:07:41 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/27 15:03:57 by daspring         ###   ########.fr       */
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

double	tuple_dot2(t_tuple *a, t_tuple *b)
{
	double	temp1;
	double	temp2;
	double	temp3;

	if (a->w == 1 && b->w == 1)
	{
		printf("tried to calculate the dot product of a point\n");
		return (nan(""));
	}
	temp1 = a->x * b->x;
	temp2 = a->y * b->y;
	temp3 = a->z * b->z;
// if (fabs(temp1) < 1E-13 && fabs(temp2) < 1E-13 && fabs(temp3) < 1E-13)
// {
// 	printf("a->x * b->x: %f, a->y * b->y: %f, a->z * b->z: %f\n", temp1, temp2, temp3);
// }
	return (temp1 + temp2 + temp3);
}

double	tuple_dot_self(t_tuple *a)
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
		return (NULL);
	}
	c->x = a->y * b->z - a->z * b->y;
	c->y = a->z * b->x - a->x * b->z;
	c->z = a->x * b->y - a->y * b->x;
	c->w = 0;
	return (c);
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
