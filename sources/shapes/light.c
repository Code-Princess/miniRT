/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:51:48 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/06 17:02:29 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../includes/objects.h"

void	init_light(t_data *data)
{
	t_object	*light;

	light = malloc(1 * sizeof(t_object));
	light->obj_name = LIGHT;
	light->identifier = L;
	light->position = set_tuple(5, -7, 15, PT);
	light->color = set_color(1, 1, 1, 1);
	light->s_light.brightness = 0.5;
	light->s_light.intensity = color_scale(light->s_light.brightness, \
											light->color);
	data->objects[8] = light;
}
