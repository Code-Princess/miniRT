/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:51:48 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/04 16:56:47 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"

void	init_light(t_data *data)
{
	t_object	*light;

	light = malloc(1 * sizeof(t_object));
	light->obj_name = LIGHT;
	light->identifier = L;
	light->position = set_tuple(-10, 10, -10, PT);
	light->color = set_color(255, 255, 255, 255);
	light->s_light.brightness = 0.5;
	light->s_light.intensity = color_scale(light->s_light.brightness, light->color);
	data->objects[8] = light;
}