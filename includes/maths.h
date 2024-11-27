/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/11/26 20:42:16 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATHS_H
# define MATHS_H

# include <stdbool.h>

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
t_tuple	tuple_add2(t_tuple *a, t_tuple *b);
t_tuple	*tuple_subtr(t_tuple *minuend, t_tuple *subtrahend);
t_tuple	tuple_subtr2(t_tuple *minuend, t_tuple *subtrahend);
t_tuple	*tuple_neg(t_tuple *a);
t_tuple	tuple_neg2(t_tuple *a);
t_tuple	*tuple_scale(float k, t_tuple *a);
t_tuple	tuple_scale2(float k, t_tuple *a);
t_tuple	*tuple_normalize(t_tuple *a);
t_tuple	tuple_normalize2(t_tuple *a);
float	tuple_magni(t_tuple *a);
float	tuple_dot(t_tuple *a, t_tuple *b);
float	tuple_dot_self(t_tuple *a);
t_tuple	*tuple_cross(t_tuple *a, t_tuple *b);
t_tuple	tuple_cross2(t_tuple *a, t_tuple *b);
float	distance(t_tuple *a, t_tuple *b);
t_tuple	*direction(t_tuple *from, t_tuple *to);
t_tuple	direction2(t_tuple *from, t_tuple *to);

float	deg_to_rad(float angle_deg);

bool	is_in_range_float(float *num, int min, int max);
bool	is_in_range_int(int *num, int min, int max);
bool	is_normalized(t_tuple *vec);

#endif
