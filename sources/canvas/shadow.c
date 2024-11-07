/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:58:38 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/07 15:13:24 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../includes/objects.h"

void	is_in_shadow(t_object *light, t_hit_obj *hit_obj)
{
	t_data		*data;
	t_ray		light_ray;
	t_hit_obj	*obstacle;

	data = get_data();
	light_ray.direction_vec = *direction(&hit_obj->hit_pt, &light->position);
	light_ray.origin_pt = hit_obj->hit_pt;
	obstacle = find_shadow_pt(data->objects, &light_ray);
	if (obstacle == NULL)
		hit_obj->not_in_shadow = true;
	else
		hit_obj->not_in_shadow = false;
}

t_hit_obj	*find_shadow_pt(t_object **objects, t_ray *ray)
{
	t_hit_obj	*hit_obj;
	float		hit_t;
	int			object_idx;

	hit_obj = malloc(1 * sizeof(t_hit_obj));
	hit_obj->t = INT8_MAX;
	object_idx = 0;
	while (objects[object_idx++] != NULL)
	{
		if (objects[object_idx - 1]->obj_name <= LIGHT)
			continue ;
		hit_t = get_hit_pt_ft()[objects[object_idx - 1]->obj_name] \
								(objects[object_idx - 1], ray);
		if (hit_t > 0 + INFINI_FLOAT && hit_t < 1 - INFINI_FLOAT)
		{
			hit_obj->t = hit_t;
			return (hit_obj);
		}
	}
	return (NULL);
}
