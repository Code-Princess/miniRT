/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:17:20 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/05 19:32:03 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <math.h>

#include "../../includes/objects.h"
#include "../../includes/color.h"

t_color	lighting_ambient(t_hit_obj *hit_obj, t_object *light, t_ray *ray)
{
	t_color	ambient_comp;
	t_color	effective_color;

	effective_color = color_mult(hit_obj->obj->color, light->s_light.intensity);
	ambient_comp = color_scale(hit_obj->obj->material.ambient, effective_color);
	return (ambient_comp);
}

// make hit_pt, normal_vec and (reflect_vec(maybe not, if we want to imlpement multiple lights) part of the hit_obj struct?
t_color	lighting(t_hit_obj *hit_obj, t_object *light, t_ray *ray)
{
	t_color	ambient_comp;
	t_color	effective_color;
	t_tuple	*light_vec;
	t_tuple	*hit_pt;
	t_tuple	*normal_vec;
	t_tuple	*reflect_vec;
	float	light_dot_normal;
	t_color	diffuse_comp;
	t_color	specular_comp;
	float	reflect_dot_eye;
	float	factor;
	t_color	result_color;

	effective_color = color_mult(hit_obj->obj->color, light->s_light.intensity);
	hit_pt = ray_at_t(ray, hit_obj->t);
	light_vec = tuple_normalize(direction(hit_pt, &light->position));
	normal_vec = get_normal_vec_ft()[hit_obj->obj->obj_name](hit_obj, ray);
	light_dot_normal = tuple_dot(light_vec, normal_vec);
	if (light_dot_normal < 0)
	{
		diffuse_comp = set_color(0, 0, 0, 1);
		specular_comp = set_color(0, 0, 0, 1);
	}
	else
	{
		diffuse_comp = color_scale(hit_obj->obj->material.diffuse * light_dot_normal, effective_color);
// 	if (hit_obj->obj->obj_name == CYLINDER)
// 	{
// // printf("light_dot_normal: %f   ", light_dot_normal);
// // print_color(diffuse_comp);
// 		// print_tuple(*normal_vec);
// 		// diffuse_comp = effective_color;
// 	}
		t_tuple	*dir_pt_light;
		dir_pt_light = direction(ray_at_t(ray, hit_obj->t), &light->position);
		reflect_vec = calc_reflect_vec(dir_pt_light, normal_vec);
		reflect_dot_eye = tuple_dot(tuple_normalize(reflect_vec), tuple_normalize(&ray->direction_vec));
		// if (hit_obj->obj->obj_name == SPHERE)
		// {
		// }
		if (reflect_dot_eye <= 0)
		{
			specular_comp = set_color(0, 0, 0, 1);
		}
		else
		{
			factor = pow(reflect_dot_eye, hit_obj->obj->material.shininess);
			specular_comp = color_scale(hit_obj->obj->material.specular * factor, light->s_light.intensity);
		}
	}
	ambient_comp = set_color(0,0,0,1);
	// diffuse_comp = set_color(0,0,0,1);
	// specular_comp = set_color(0,0,0,1);
	result_color = color_add(ambient_comp, diffuse_comp);
	result_color = color_add(result_color, specular_comp);
	return (result_color);
}

t_tuple	*calc_reflect_vec2(t_hit_obj *hit_obj, t_ray *ray, t_tuple *normal_vec)
{
	t_tuple	*reflect_vec;
	t_tuple	*subtrahend;
	float	ray_dot_normal;

	ray_dot_normal = tuple_dot(&ray->direction_vec, normal_vec);
	subtrahend = tuple_scale(2 * ray_dot_normal, normal_vec);
	reflect_vec = tuple_subtr(&ray->direction_vec, subtrahend);
	return (reflect_vec);
}

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
