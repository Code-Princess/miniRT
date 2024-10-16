/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:16:05 by daspring          #+#    #+#             */
/*   Updated: 2024/10/16 12:15:33 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <stddef.h>

# include "miniRT.h"
# include "maths.h"

typedef struct s_data t_data;

typedef struct s_ray
{
	t_tuple	eye_point;
	t_tuple	direction_vec;
}		t_ray;


// t_ray	create_ray(t_tuple E, t_tuple P);
t_ray	*create_ray(size_t x_pixel, size_t y_pixel);

#endif
