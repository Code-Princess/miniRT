/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:17:20 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/26 13:51:31 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <math.h>
#include <stdlib.h>

#include "../../includes/objects.h"
#include "../../includes/color.h"

t_color	calc_ambient_color(t_hit_obj *hit_obj, t_object *light)
{
	t_color	ambient_comp;
	t_color	effective_color;
	int		idx_ambient_light;
	t_data	*data;

(void)light;
	data = get_data();
	idx_ambient_light = get_object_index(data, A);
	// effective_color = color_mult(hit_obj->obj->color, light->s_light.intensity);
	effective_color = color_mult(hit_obj->obj->color, data->objects[idx_ambient_light]->color);
	ambient_comp = color_scale(data->objects[idx_ambient_light]->s_amb_light.brightness, effective_color);
	return (ambient_comp);
}

t_color	calc_diffuse_color(t_hit_obj *hit_obj, t_object *light)
{
	t_color	diffuse_color;
	t_color	effective_color;
	t_tuple	*light_vec;
	float	light_dot_normal;

	effective_color = color_mult(hit_obj->obj->color, light->s_light.intensity);
	light_vec = tuple_normalize(direction(&hit_obj->hit_pt, &light->position));
	light_dot_normal = tuple_dot(light_vec, &hit_obj->normal_vec);
	if (light_dot_normal < 0)
		diffuse_color = set_color(0, 0, 0, 1);
	else
		diffuse_color = color_scale(hit_obj->obj->material.diffuse * \
										light_dot_normal, effective_color);
	return (diffuse_color);
}

t_color	calc_specular_color(t_hit_obj *hit_obj, t_object *light, t_ray *ray)
{
	t_tuple	*light_vec;
	float	light_dot_normal;
	t_tuple	*dir_pt_light;
	t_tuple	*reflect_vec;
	float	reflect_dot_eye;
	t_tuple	pt;

	light_vec = tuple_normalize(direction(&hit_obj->hit_pt, &light->position));
	light_dot_normal = tuple_dot(light_vec, &hit_obj->normal_vec);
	if (light_dot_normal < 0)
		return (set_color(0, 0, 0, 1));
	else
	{
		pt = ray_at_t(ray, hit_obj->t);
		dir_pt_light = direction(&pt, &light->position);
		reflect_vec = calc_reflect_vec(dir_pt_light, &hit_obj->normal_vec);
		reflect_dot_eye = tuple_dot(tuple_normalize(reflect_vec), \
									tuple_normalize(&ray->direction_vec));
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

void	prepare_color_calc(t_hit_obj *hit_obj, t_ray *ray)
{
	hit_obj->hit_pt = ray_at_t(ray, hit_obj->t);
	hit_obj->normal_vec = *get_normal_vec_ft()[hit_obj->obj->obj_name] \
											(hit_obj, ray);
}
// printf("still alive in prepare_color_calc!\n");

t_tuple	*calc_reflect_vec(t_tuple *incomming, t_tuple *normal_vec)
{
	t_tuple	*reflect_vec;
	t_tuple	*subtrahend;
	float	ray_dot_normal;

	ray_dot_normal = tuple_dot(incomming, normal_vec);
	subtrahend = tuple_scale(2 * ray_dot_normal, normal_vec);
	reflect_vec = tuple_subtr(incomming, subtrahend);
	return (reflect_vec);
}
