/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_amb_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:51:34 by daspring          #+#    #+#             */
/*   Updated: 2024/11/08 18:43:19 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/objects.h"

t_object	*parse_amb_light_input(char **line)
{
	t_object	*amb_light;
	char		**input_color_array;

	amb_light->obj_name = AMB_LIGHT;
	amb_light->identifier = A;
	amb_light = ft_calloc(1, sizeof(t_object));
printf("alive in parse_amb_light_input\n");
	amb_light->s_amb_light.brightness = ft_atof(line[1]);
	input_color_array = ft_split(line[2], ',');
// check for NULL

	amb_light->color = set_color(ft_atof(input_color_array[0]) / 255, \
									ft_atof(input_color_array[1]) / 255, \
									ft_atof(input_color_array[2]) / 255, \
									1);
	free(input_color_array);
	return (amb_light);
}