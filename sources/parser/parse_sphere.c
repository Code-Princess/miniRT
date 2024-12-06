/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:51:34 by daspring          #+#    #+#             */
/*   Updated: 2024/12/06 13:42:14 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../includes/utilities.h"
#include "../../libft/libft.h"

t_object	*parse_sphere_input(char **line_arr)
{
	t_object			*sphere;
	int					idx;

	sphere = ft_calloc(1, sizeof(t_object));
	if (sphere == NULL)
		error_and_exit2("Malloc failed.\n", "input", NULL);
	sphere->obj_name = SPHERE;
	sphere->identifier = SP;
	idx = 1;
	init_position(sphere, line_arr, idx);
	idx += 3;
	init_radius(sphere, line_arr, idx);
	init_color(sphere, line_arr, ++idx);
	sphere->material = set_material(AMBIENT, 0.7, 0.7, 100);
	return (sphere);
}
