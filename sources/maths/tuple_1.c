/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:40:45 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/10 20:25:05 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/maths.h"

t_tuple	tuple_add(t_tuple a, t_tuple b)
{
	t_tuple	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	c.w = a.w + b.w;
	return (c);
}

t_tuple	tuple_neg(t_tuple a)
{
	t_tuple	c;

	c.x = -(a.x);
	c.y = -(a.y);
	c.z = -(a.z);
	c.w = a.w;
	return (c);
}

t_tuple	tuple_subtr(t_tuple a, t_tuple b)
{
	t_tuple	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	c.w = a.w - b.w;
	return (c);
}

t_tuple	tuple_scale(float k, t_tuple a)
{
	t_tuple	c;

	c.x = k * a.x;
	c.y = k * a.y;
	c.z = k * a.z;
	c.w = a.w;
	return (c);
}
