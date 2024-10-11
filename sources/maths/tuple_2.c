/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:53:23 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/11 12:08:44 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../includes/maths.h"

float	tuple_magni(t_tuple a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_tuple	tuple_normalize(t_tuple a)
{
	t_tuple	c;

	c.x = a.x / tuple_magni(a);
	c.y = a.y / tuple_magni(a);
	c.z = a.z / tuple_magni(a);
	c.w = 0;
	return (c);
}

float	distance(t_tuple a, t_tuple b)
{
	return (tuple_magni(tuple_subtr(a, b)));
}

t_tuple	direction(t_tuple a, t_tuple b)
{
	return (tuple_subtr(b, a));
}
