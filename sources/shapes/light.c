/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:51:48 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/05 17:52:33 by daspring         ###   ########.fr       */
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
	light->position = set_tuple(0, 0, -10, PT);
	light->color = set_color(1, 1, 1, 1);
	light->s_light.brightness = 1;
	light->s_light.intensity = color_scale(light->s_light.brightness, \
											light->color);
	data->objects[8] = light;
}
