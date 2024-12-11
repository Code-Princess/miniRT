/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:58:38 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/11 16:09:18 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../includes/objects.h"

void	is_in_shadow(t_object *light, t_hit_obj *hit_obj)
{
	t_data		*data;
	t_ray		light_ray;

	data = get_data();
	light_ray.direction_vec = direction(&hit_obj->hit_pt, &light->position);
	light_ray.origin_pt = hit_obj->hit_pt;
	if (pt_is_in_shadow(data->objects, &light_ray))
		hit_obj->not_in_shadow = false;
	else
		hit_obj->not_in_shadow = true;
}

#include <stdio.h>
// get_hit_pt_fcts do work for rays cast from the eye-point. lets look at this ray here again ...
bool	pt_is_in_shadow(t_object **objects, t_ray *ray)
{
	double		hit_t;
	int			object_idx;

	object_idx = 0;
	while (objects[object_idx++] != NULL)
	{
		if (objects[object_idx - 1]->obj_name <= LIGHT)
			continue ;
		hit_t = get_hit_pt_ft()[objects[object_idx - 1]->obj_name] \
								(objects[object_idx - 1], ray);
		// if (hit_t > 0 + INFINI_FLOAT && hit_t < 1 - INFINI_FLOAT)
		if (hit_t > 0 + INFINI_FLOAT && hit_t < 1 - INFINI_FLOAT)
		{
// printf("pt_is_in_shadow - hit_t: %f\n", hit_t);
			return (true);
		}
	}
	return (false);
}
