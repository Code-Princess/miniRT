/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:48:46 by linda             #+#    #+#             */
/*   Updated: 2024/10/15 18:48:21 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../includes/miniRT.h"
#include "../../includes/objects.h"
#include "../../includes/maths.h"
#include "../../includes/color.h"

void	init_plane(t_data *data)
{
	t_object    plane;

	plane.obj_name = PLANE;
	plane.identifier = PL;
	plane.position.x = 0;
	plane.position.y = 0;
	plane.position.z = 50;
	plane.position.w = PT;
	plane.s_plane.color.colors[RED] = 0;
	plane.s_plane.color.colors[GREEN] = 0;
	plane.s_plane.color.colors[BLUE] = 255;
	plane.s_plane.color.colors[OPAC] = 255;
	plane.s_plane.normal_vec = tuple_normalize((t_tuple){0, 0, 1, VEC});
	data->objects[2] = plane;
	
	plane.obj_name = PLANE;
	plane.identifier = PL;
	plane.position.x = 0;
	plane.position.y = 0;
	plane.position.z = 50;
	plane.position.w = PT;
	plane.s_plane.color.colors[RED] = 0;
	plane.s_plane.color.colors[GREEN] = 150;
	plane.s_plane.color.colors[BLUE] = 0;
	plane.s_plane.color.colors[OPAC] = 255;
	plane.s_plane.normal_vec = tuple_normalize((t_tuple){-1, 0, -1, VEC});
	data->objects[3] = plane;
}
