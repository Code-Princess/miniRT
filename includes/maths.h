/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:41:11 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/29 20:52:47 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	int		w;
}		t_tuple;

typedef enum e_tuple_type
{
	VEC,
	PT
}		t_tuple_type;

t_tuple	set_tuple(float x, float y, float z, int w);
t_tuple	*tuple_add(t_tuple *a, t_tuple *b);
t_tuple	*tuple_subtr(t_tuple *minuend, t_tuple *subtrahend);
t_tuple	*tuple_neg(t_tuple *a);
t_tuple	*tuple_scale(float k, t_tuple *a);
t_tuple	*tuple_normalize(t_tuple *a);
float	tuple_magni(t_tuple *a);
float	tuple_dot(t_tuple *a, t_tuple *b);
float	tuple_dot_self(t_tuple *a);
t_tuple	*tuple_cross(t_tuple *a, t_tuple *b);
float	distance(t_tuple *a, t_tuple *b);
t_tuple	*direction(t_tuple *from, t_tuple *to);

float	deg_to_rad(float angle_deg);

#endif
