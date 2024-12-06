/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:17:31 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/06 13:19:16 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <stdbool.h>

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	int		w;
}		t_tuple;

typedef enum e_tuple_type
{
	VEC,
	PT
}		t_tuple_type;

t_tuple	set_tuple(double x, double y, double z, int w);
t_tuple	tuple_add2(t_tuple *a, t_tuple *b);
t_tuple	tuple_subtr2(t_tuple *minuend, t_tuple *subtrahend);
t_tuple	tuple_neg2(t_tuple *a);
t_tuple	tuple_scale2(double k, t_tuple *a);
t_tuple	tuple_normalize2(t_tuple *a);
double	tuple_magni(t_tuple *a);
double	tuple_dot(t_tuple *a, t_tuple *b);
double	tuple_dot_self(t_tuple *a);
t_tuple	tuple_cross2(t_tuple *a, t_tuple *b);
double	distance(t_tuple *a, t_tuple *b);
t_tuple	direction2(t_tuple *from, t_tuple *to);

double	deg_to_rad(double angle_deg);

bool	is_in_range_float(double *num, int min, int max);
bool	is_in_range_int(int *num, int min, int max);
bool	is_normalized(t_tuple *vec);

#endif
