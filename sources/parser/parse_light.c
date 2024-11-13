/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:51:34 by daspring          #+#    #+#             */
/*   Updated: 2024/11/13 13:05:17 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../libft/libft.h"

t_object	*parse_light_input(char **line_arr)
{
	t_object			*light;
	int					idx;
	static int			light_counter;

	light_counter++;
	if (light_counter > 1)
		; // error!
	light = ft_calloc(1, sizeof(t_object));
	light->obj_name = LIGHT;
	light->identifier = L;
	idx = 1;
	init_position(light, line_arr, idx);
	idx += 3;
	init_brightness(light, line_arr, idx);
	// init_color(light, line_arr, ++idx); // only for bonus
	light->color = set_color(1, 1, 1, 1);
	light->s_light.intensity = color_scale(light->s_light.brightness, \
											light->color);
	return (light);
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
