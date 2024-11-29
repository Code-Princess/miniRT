/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:36:57 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/29 17:51:30 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../includes/maths.h"

t_tuple	tuple_add2(t_tuple *a, t_tuple *b)
{
	t_tuple	c;

	c.x = a->x + b->x;
	c.y = a->y + b->y;
	c.z = a->z + b->z;
	c.w = a->w + b->w;
	return (c);
}

t_tuple	tuple_neg2(t_tuple *a)
{
	t_tuple	c;

	c.x = -(a->x);
	c.y = -(a->y);
	c.z = -(a->z);
	c.w = a->w;
	return (c);
}

t_tuple	tuple_subtr2(t_tuple *minuend, t_tuple *subtrahend)
{
	t_tuple	c;

	c.x = minuend->x - subtrahend->x;
	c.y = minuend->y - subtrahend->y;
	c.z = minuend->z - subtrahend->z;
	c.w = minuend->w - subtrahend->w;
	return (c);
}

t_tuple	tuple_scale2(double k, t_tuple *a)
{
	t_tuple	c;

	c.x = k * a->x;
	c.y = k * a->y;
	c.z = k * a->z;
	c.w = a->w;
	return (c);
}

t_tuple	set_tuple(double x, double y, double z, int w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}
