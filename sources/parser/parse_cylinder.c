/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:59:40 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/05 19:18:59 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../includes/utilities.h"
#include "../../libft/libft.h"

t_object	*parse_cylinder_input(char **line_arr)
{
	t_object			*cylinder;
	int					idx;

	cylinder = ft_calloc(1, sizeof(t_object));
	if (cylinder == NULL)
		error_and_exit("Malloc failed.\n", "input", NULL);
	cylinder->obj_name = CYLINDER;
	cylinder->identifier = CY;
	idx = 1;
	init_position(cylinder, line_arr, idx);
	idx += 3;
	init_axis_vec(cylinder, line_arr, idx);
	idx += 3;
	init_radius(cylinder, line_arr, idx);
	idx++;
	init_height(cylinder, line_arr, idx);
	idx++;
	init_color(cylinder, line_arr, idx);
	cylinder->material = set_material(AMBIENT, 0.7, 0.7, 50);
	return (cylinder);
}
