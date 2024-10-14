/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:41:11 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/14 12:49:28 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	int		w; // w=0 for vector, w=1 for point
}		t_tuple;

t_tuple	tuple_add(t_tuple a, t_tuple b);
t_tuple	tuple_subtr(t_tuple a, t_tuple b);
t_tuple	tuple_neg(t_tuple a);
t_tuple	tuple_scale(float k, t_tuple a);
t_tuple	tuple_normalize(t_tuple a);
float	tuple_magni(t_tuple a);
float	tuple_dot(t_tuple a, t_tuple b);
t_tuple	tuple_cross(t_tuple a, t_tuple b);
float	distance(t_tuple a, t_tuple b);
t_tuple	direction(t_tuple a, t_tuple b);

float	deg_to_rad (float angle_deg);

#endif
