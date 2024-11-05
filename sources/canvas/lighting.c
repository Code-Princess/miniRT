/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:17:20 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/05 12:58:58 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../includes/objects.h"
#include "../../includes/color.h"

t_color lighting(t_hit_obj *hit_obj, t_object *light, t_ray *ray)
{
	t_color effective_color;
	t_tuple *light_vec;
	t_tuple *hit_pt;
	t_tuple *normal_vec;
	t_tuple *reflect_vec;
	float	light_dot_normal;
	t_color	ambient_comp;
	t_color	diffuse_comp;
	t_color	specular_comp;
	float	reflect_dot_eye;
	float	factor;
	t_color result_color;

	effective_color = color_mult(hit_obj->obj->color, light->s_light.intensity);
	hit_pt = ray_at_t(ray, hit_obj->t);
	light_vec = tuple_normalize(direction(hit_pt, &light->position));
	ambient_comp = color_scale(hit_obj->obj->material.ambient, effective_color);
	normal_vec = get_normal_vec_ft()[hit_obj->obj->obj_name](hit_obj, ray);
	light_dot_normal = tuple_dot(light_vec, normal_vec);

	if (light_dot_normal < 0)
	{
		hit_obj->obj->material.diffuse = 0;
		hit_obj->obj->material.specular = 0;
	}
	else
	{
		diffuse_comp = color_scale(hit_obj->obj->material.diffuse * light_dot_normal, effective_color);
		t_tuple	*dir_pt_light;
		dir_pt_light = direction(ray_at_t(ray, hit_obj->t), &light->position);
		reflect_vec = calc_reflect_vec(dir_pt_light, normal_vec);
		// reflect_vec = calc_reflect_vec(&ray->direction_vec, normal_vec);
		// reflect_vec = calc_reflect_vec(hit_obj, tuple_neg(light_vec), normal_vec);
		reflect_dot_eye = tuple_dot(reflect_vec, &ray->direction_vec);
		if (reflect_dot_eye <= 0)
		{
			hit_obj->obj->material.specular = 0;
		}
		else
		{
			factor = pow(reflect_dot_eye, hit_obj->obj->material.shininess);
			specular_comp = color_scale(hit_obj->obj->material.specular * factor, light->s_light.intensity);
		}
	}
	// ambient_comp = set_color(0,0,0,1);
	// diffuse_comp = set_color(0,0,0,1);
	// specular_comp = set_color(0,0,0,1);
	result_color = color_add(ambient_comp, diffuse_comp);
	result_color = color_add(result_color, specular_comp);
	// result_color = color_add(set_color(0,0,0,1), diffuse_comp);
	// result_color = color_add(result_color, set_color(0,0,0,1));
	// result_color = set_color(ambient_comp, diffuse_comp, specular_comp, 1); //// How to make a color?
	return (result_color);
}



t_tuple *calc_reflect_vec2(t_hit_obj *hit_obj, t_ray *ray, t_tuple *normal_vec)
{
	t_tuple *reflect_vec;
	t_tuple *subtrahend;
	float ray_dot_normal;

	ray_dot_normal = tuple_dot(&ray->direction_vec, normal_vec);
	subtrahend = tuple_scale(2 * ray_dot_normal, normal_vec);
	reflect_vec = tuple_subtr(&ray->direction_vec, subtrahend);
	return (reflect_vec);
}

t_tuple *calc_reflect_vec(t_tuple *incomming, t_tuple *normal_vec)
{
	t_tuple *reflect_vec;
	t_tuple *subtrahend;
	float ray_dot_normal;

	ray_dot_normal = tuple_dot(incomming, normal_vec);
	subtrahend = tuple_scale(2 * ray_dot_normal, normal_vec);
	reflect_vec = tuple_subtr(incomming, subtrahend);
	return (reflect_vec);
}