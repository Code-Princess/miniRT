/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:59:40 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/21 13:34:26 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../includes/utilities.h"
#include "../../libft/libft.h"

t_object	*parse_plane_input(char **line_arr)
{
	t_object			*plane;
	int					idx;
	// static int			plane_counter;

	// plane_counter++;
	plane = ft_calloc(1, sizeof(t_object));
	plane->obj_name = PLANE;
	plane->identifier = PL;
	idx = 1;
	init_position(plane, line_arr, idx);
	idx += 3;
	init_normal_vec(plane, line_arr, idx);
	idx += 3;
	init_color(plane, line_arr, idx);
	plane->material = set_material(AMBIENT, 0.7, 0.7, 50);
	return (plane);
}
