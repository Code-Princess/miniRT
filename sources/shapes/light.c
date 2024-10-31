/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:51:48 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/31 16:55:03 by llacsivy         ###   ########.fr       */
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
	data->objects[8] = light;
}