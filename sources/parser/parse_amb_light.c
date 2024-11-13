/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_amb_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:51:34 by daspring          #+#    #+#             */
/*   Updated: 2024/11/13 19:46:22 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../libft/libft.h"

t_object	*parse_amb_light_input(char **line_arr)
{
	t_object			*amb_light;
	int					idx;
	static int			ambient_counter;

	ambient_counter++;
	if (ambient_counter > 1)
		; // error! too many ambient lights
	amb_light = ft_calloc(1, sizeof(t_object));
	amb_light->obj_name = AMB_LIGHT;
	amb_light->identifier = A;
	idx = 1;
	init_brightness(amb_light, line_arr, idx);
	idx += 1;
	init_color(amb_light, line_arr, idx);
	return (amb_light);
}
