/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_amb_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:51:34 by daspring          #+#    #+#             */
/*   Updated: 2024/11/11 16:25:05 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/objects.h"

t_object	*parse_amb_light_input(char **line_arr)
{
	t_object			*amb_light;
	char				**input_color_array;
	int					pos;
	static int			ambient_counter;
	static const char	pattern[] = "IBC";
	static const char	pattern[] = "IBCCC";

	ambient_counter++;
	if (ambient_counter > 1)
		; // error! too many ambient lights
	amb_light = ft_calloc(1, sizeof(t_object));
	amb_light->obj_name = AMB_LIGHT;
	amb_light->identifier = A;
init_brightness(amb_light, line_arr, 1);
init_color(amb_light, line_arr, 2);
	return (amb_light);
}

// printf("alive in parse_amb_light_input\n");
// 	amb_light->s_amb_light.brightness = ft_atof(line_arr[1]);
// 	input_color_array = ft_split(line_arr[2], ',');
// // check for NULL

// 	amb_light->color = set_color(ft_atof(input_color_array[0]) / 255, \
// 									ft_atof(input_color_array[1]) / 255, \
// 									ft_atof(input_color_array[2]) / 255, \
// 									1);
// 	free(input_color_array);
