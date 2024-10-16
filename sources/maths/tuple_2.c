/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:53:23 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/16 11:47:18 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include "../../includes/maths.h"

float	tuple_magni(t_tuple *a)
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

float	distance(t_tuple *a, t_tuple *b)
{
	return (tuple_magni(tuple_subtr(a, b)));
}

t_tuple	*direction(t_tuple *a, t_tuple *b)
{
	
	return (tuple_subtr(b, a));
}
