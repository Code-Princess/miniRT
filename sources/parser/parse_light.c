/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:51:34 by daspring          #+#    #+#             */
/*   Updated: 2024/11/13 19:45:35 by llacsivy         ###   ########.fr       */
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
