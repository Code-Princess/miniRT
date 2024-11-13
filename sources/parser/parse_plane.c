/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:59:40 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/13 17:35:38 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../libft/libft.h"

t_object	*parse_plane_input(char **line_arr)
{
	t_object			*plane;
	int					idx;
	static int			plane_counter;

	plane_counter++;
	if (plane_counter > 1)
		; // error!
	plane = ft_calloc(1, sizeof(t_object));
	plane->obj_name = PLANE;
	plane->identifier = PL;
	idx = 1;
	init_position(plane, line_arr, idx);
	idx += 3;
	init_normal_vec(plane, line_arr, idx);
	idx += 3;
	init_color(plane, line_arr, idx);
	plane->material = set_material(0.2, 0.7, 0.7, 50);
	return (plane);
}