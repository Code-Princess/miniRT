/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_amb_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:51:34 by daspring          #+#    #+#             */
/*   Updated: 2024/11/12 15:10:36 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../libft/libft.h"

t_object	*parse_amb_light_input(char **line_arr)
{
	t_object			*amb_light;
	char				**input_color_array;
	int					idx;
	static int			ambient_counter;

printf("parsing amb_light\n");

	ambient_counter++;
	if (ambient_counter > 1)
		; // error! too many ambient lights
	amb_light = ft_calloc(1, sizeof(t_object));
	amb_light->obj_name = AMB_LIGHT;
	amb_light->identifier = A;
	idx = 0;
	init_brightness(amb_light, line_arr, ++idx);
	init_color(amb_light, line_arr, ++idx);
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
