/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:40:45 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/26 13:54:19 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../includes/maths.h"

t_tuple	*tuple_add(t_tuple *a, t_tuple *b)
{
	t_tuple	*c;

	c = malloc(1 * sizeof(t_tuple));
	c->x = a->x + b->x;
	c->y = a->y + b->y;
	c->z = a->z + b->z;
	c->w = a->w + b->w;
	return (c);
}

t_tuple	tuple_add2(t_tuple *a, t_tuple *b)
{
	t_tuple	c;

	c.x = a->x + b->x;
	c.y = a->y + b->y;
	c.z = a->z + b->z;
	c.w = a->w + b->w;
	return (c);
}

t_tuple	*tuple_neg(t_tuple *a)
{
	t_tuple	*c;

	c = malloc(1 * sizeof(t_tuple));
	c->x = -(a->x);
	c->y = -(a->y);
	c->z = -(a->z);
	c->w = a->w;
	return (c);
}

t_tuple	*tuple_subtr(t_tuple *minuend, t_tuple *subtrahend)
{
	t_tuple	*c;

	c = malloc(1 * sizeof(t_tuple));
	c->x = minuend->x - subtrahend->x;
	c->y = minuend->y - subtrahend->y;
	c->z = minuend->z - subtrahend->z;
	c->w = minuend->w - subtrahend->w;
	return (c);
}

t_tuple	*tuple_scale(float k, t_tuple *a)
{
	t_tuple	*c;

	c = malloc(1 * sizeof(t_tuple));
	c->x = k * a->x;
	c->y = k * a->y;
	c->z = k * a->z;
	c->w = a->w;
	return (c);
}

t_tuple	tuple_scale2(float k, t_tuple *a)
{
	t_tuple	c;

	c.x = k * a->x;
	c.y = k * a->y;
	c.z = k * a->z;
	c.w = a->w;
	return (c);
}

t_tuple	set_tuple(float x, float y, float z, int w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}
