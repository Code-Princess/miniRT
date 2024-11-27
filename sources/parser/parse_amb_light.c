/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_amb_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:51:34 by daspring          #+#    #+#             */
/*   Updated: 2024/11/25 13:41:54 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../libft/libft.h"
#include "../../includes/utilities.h"

t_object	*parse_amb_light_input(char **line_arr)
{
	t_object			*amb_light;
	int					idx;
	static int			ambient_counter;

	ambient_counter++;
	if (ambient_counter > 1)
	{
		print_error_and_exit2("Too many ambient lights.", "A");
	}
	amb_light = ft_calloc(1, sizeof(t_object));
	amb_light->obj_name = AMB_LIGHT;
	amb_light->identifier = A;
	idx = 1;
	init_brightness(amb_light, line_arr, idx);
	idx += 1;
	init_color(amb_light, line_arr, idx);
	return (amb_light);
}
