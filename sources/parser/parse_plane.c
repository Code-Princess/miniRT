/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:59:40 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/06 13:42:14 by llacsivy         ###   ########.fr       */
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

	plane = ft_calloc(1, sizeof(t_object));
	if (plane == NULL)
		error_and_exit2("Malloc failed.\n", "input", NULL);
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
