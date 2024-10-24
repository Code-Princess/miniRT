/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:16:05 by daspring          #+#    #+#             */
/*   Updated: 2024/10/24 15:30:38 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <stddef.h>

# include "miniRT.h"
# include "maths.h"

typedef struct s_data	t_data;

typedef struct s_ray
{
	t_tuple	origin_pt;
	t_tuple	direction_vec;
}		t_ray;

// t_ray	create_ray(t_tuple E, t_tuple P);
t_ray	*create_ray(size_t x_pixel, size_t y_pixel);
t_tuple	*ray_at_t(t_ray ray, float t);

#endif
