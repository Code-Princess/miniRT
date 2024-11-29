/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:53:23 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/29 15:26:53 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include "../../includes/maths.h"
#include "../../includes/miniRT.h"

double	tuple_magni(t_tuple *a)
{
	return (sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
}

t_tuple	*tuple_normalize(t_tuple *a)
{
	t_tuple	*c;

	c = malloc(1 * sizeof(t_tuple));
	c->x = a->x / tuple_magni(a);
	c->y = a->y / tuple_magni(a);
	c->z = a->z / tuple_magni(a);
	c->w = a->w;
	return (c);
}

t_tuple	tuple_normalize2(t_tuple *a)
{
	t_tuple	c;

	c.x = a->x / tuple_magni(a);
	c.y = a->y / tuple_magni(a);
	c.z = a->z / tuple_magni(a);
	c.w = a->w;
	return (c);
}

bool	is_normalized(t_tuple *vec)
{
	if (fabs(tuple_magni(vec) - 1) <= INFINI_FLOAT)
		return (true);
	else
		return (false);
}

double	distance(t_tuple *a, t_tuple *b)
{
	t_tuple	temp;

	temp = tuple_subtr2(a, b);
	return (tuple_magni(&temp));
}

t_tuple	*direction(t_tuple *from, t_tuple *to)
{
	return (tuple_subtr(to, from));
}

t_tuple	direction2(t_tuple *from, t_tuple *to)
{
	return (tuple_subtr2(to, from));
}
