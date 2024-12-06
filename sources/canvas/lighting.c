/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:17:20 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/06 13:15:32 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <math.h>
#include <stdlib.h>

#include "../../includes/objects.h"
#include "../../includes/color.h"

bool	pt_is_on_far_side(t_hit_obj *hit_obj, t_object *light);

t_color	calc_ambient_color(t_hit_obj *hit_obj, t_object *light)
{
	t_color	ambient_comp;
	t_color	effective_color;
	int		idx_ambient_light;
	t_data	*data;

	(void)light;
	data = get_data();
	idx_ambient_light = get_object_index(data, A);
	effective_color = color_mult(hit_obj->obj->color, data->objects \
									[idx_ambient_light]->color);
	ambient_comp = color_scale(data->objects[idx_ambient_light]->\
									s_amb_light.brightness, effective_color);
	return (ambient_comp);
}

t_color	calc_diffuse_color(t_hit_obj *hit_obj, t_object *light)
{
	t_color	diffuse_color;
	t_color	effective_color;
	t_tuple	light_vec;
	double	light_dot_normal;
	t_tuple	temp;

	effective_color = color_mult(hit_obj->obj->color, light->s_light.intensity);
	temp = direction2(&hit_obj->hit_pt, &light->position);
	light_vec = tuple_normalize2(&temp);
	light_dot_normal = tuple_dot(&light_vec, &hit_obj->normal_vec);
	if (light_dot_normal < 0)
		diffuse_color = set_color(0, 0, 0, 1);
	else
		diffuse_color = color_scale(hit_obj->obj->material.diffuse * \
										light_dot_normal, effective_color);
	return (diffuse_color);
}

t_color	calc_specular_color(t_hit_obj *hit_obj, t_object *light, t_ray *ray)
{
	t_tuple	dir_pt_light;
	t_tuple	reflect_vec;
	double	reflect_dot_eye;
	t_tuple	temp;
	t_tuple	temp2;

	if (pt_is_on_far_side(hit_obj, light))
		return (set_color(0, 0, 0, 1));
	else
	{
		temp = ray_at_t(ray, hit_obj->t);
		dir_pt_light = direction2(&temp, &light->position);
		reflect_vec = calc_reflect_vec(&dir_pt_light, &hit_obj->normal_vec);
		temp = tuple_normalize2(&reflect_vec);
		temp2 = tuple_normalize2(&ray->direction_vec);
		reflect_dot_eye = tuple_dot(&temp, &temp2);
		if (reflect_dot_eye <= 0)
			return (set_color(0, 0, 0, 1));
		else
		{
			return (color_scale(hit_obj->obj->material.specular * \
					pow(reflect_dot_eye, hit_obj->obj->material.shininess), \
						light->s_light.intensity));
		}
	}
}

bool	pt_is_on_far_side(t_hit_obj *hit_obj, t_object *light)
{
	t_tuple	light_vec;
	double	light_dot_normal;
	t_tuple	temp;

	temp = direction2(&hit_obj->hit_pt, &light->position);
	light_vec = tuple_normalize2(&temp);
	light_dot_normal = tuple_dot(&light_vec, &hit_obj->normal_vec);
	return (light_dot_normal < 0);
}

t_tuple	calc_reflect_vec(t_tuple *incomming, t_tuple *normal_vec)
{
	t_tuple	reflect_vec;
	t_tuple	subtrahend;
	double	ray_dot_normal;

	ray_dot_normal = tuple_dot(incomming, normal_vec);
	subtrahend = tuple_scale2(2 * ray_dot_normal, normal_vec);
	reflect_vec = tuple_subtr2(incomming, &subtrahend);
	return (reflect_vec);
}
