/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:51:34 by daspring          #+#    #+#             */
/*   Updated: 2024/12/05 19:18:59 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../includes/utilities.h"
#include "../../includes/free.h"
#include "../../libft/libft.h"

t_object	*parse_light_input(char **line_arr)
{
	t_object			*light;
	int					idx;
	static int			light_counter;
	t_data				*data;

	data = get_data();
	light_counter++;
	if (light_counter > 1)
		error_and_exit("Too many lights.", "L", NULL);
	light = ft_calloc(1, sizeof(t_object));
	if (light == NULL)
		error_and_exit("Malloc failed.\n", "input", NULL);
	light->obj_name = LIGHT;
	light->identifier = L;
	idx = 1;
	init_position(light, line_arr, idx);
	idx += 3;
	init_brightness(light, line_arr, idx);
	light->color = set_color(1, 1, 1, 1);
	light->s_light.intensity = color_scale(light->s_light.brightness, \
											light->color);
	return (light);
}
