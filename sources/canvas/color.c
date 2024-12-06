/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:42:09 by daspring          #+#    #+#             */
/*   Updated: 2024/12/06 13:17:05 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/color.h"
#include "../../includes/objects.h"

t_color	set_color(double r, double g, double b, double opac)
{
	t_color	color;

	color.colors_float[RED] = r;
	color.colors_float[GREEN] = g;
	color.colors_float[BLUE] = b;
	color.colors_float[OPAC] = opac;
	return (color);
}

t_color	color_mult(t_color a, t_color b)
{
	t_color	result;

	result.colors_float[RED] = a.colors_float[RED] * b.colors_float[RED];
	result.colors_float[GREEN] = a.colors_float[GREEN] * b.colors_float[GREEN];
	result.colors_float[BLUE] = a.colors_float[BLUE] * b.colors_float[BLUE];
	result.colors_float[OPAC] = a.colors_float[OPAC] * b.colors_float[OPAC];
	return (result);
}

t_color	color_add(t_color a, t_color b)
{
	t_color	result;

	result.colors_float[RED] = a.colors_float[RED] + b.colors_float[RED];
	result.colors_float[GREEN] = a.colors_float[GREEN] + b.colors_float[GREEN];
	result.colors_float[BLUE] = a.colors_float[BLUE] + b.colors_float[BLUE];
	result.colors_float[OPAC] = a.colors_float[OPAC] + b.colors_float[OPAC];
	return (result);
}

t_color	color_scale(double k, t_color a)
{
	t_color	result;

	result.colors_float[RED] = a.colors_float[RED] * k;
	result.colors_float[GREEN] = a.colors_float[GREEN] * k;
	result.colors_float[BLUE] = a.colors_float[BLUE] * k;
	result.colors_float[OPAC] = a.colors_float[OPAC] * k;
	return (result);
}

void	prepare_color_calc(t_hit_obj *hit_obj, t_ray *ray)
{
	hit_obj->hit_pt = ray_at_t(ray, hit_obj->t);
	hit_obj->normal_vec = get_normal_vec_ft()[hit_obj->obj->obj_name] \
											(hit_obj, ray);
}
