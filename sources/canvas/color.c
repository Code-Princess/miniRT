/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:42:09 by daspring          #+#    #+#             */
/*   Updated: 2024/11/05 11:26:20 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/color.h"
#include "../../includes/objects.h"

t_color	set_color(float r, float g, float b, float opac)
{
	t_color	color;

	color.colors_float[RED] = r;
	color.colors_float[GREEN] = g;
	color.colors_float[BLUE] = b;
	color.colors_float[OPAC] = opac;
	return (color);
}

t_material	set_material(float ambient, float diffuse, float specular, \
							int shininess)
{
	t_material	material;

	material.ambient = ambient;
	material.diffuse = diffuse;
	material.specular = specular;
	material.specular = specular;
	return (material);
}

t_color	color_mult(t_color a, t_color b)
{
	t_color result;

	result.colors_float[RED] = a.colors_float[RED] * b.colors_float[RED];
	result.colors_float[GREEN] = a.colors_float[GREEN] * b.colors_float[GREEN];
	result.colors_float[BLUE] = a.colors_float[BLUE] * b.colors_float[BLUE];
	result.colors_float[OPAC] = a.colors_float[OPAC] * b.colors_float[OPAC];
	result.colors_float[OPAC] = 1;
	return (result);
}

t_color	color_add(t_color a, t_color b)
{
	t_color result;

	result.colors_float[RED] = a.colors_float[RED] + b.colors_float[RED];
	result.colors_float[GREEN] = a.colors_float[GREEN] + b.colors_float[GREEN];
	result.colors_float[BLUE] = a.colors_float[BLUE] + b.colors_float[BLUE];
	result.colors_float[OPAC] = a.colors_float[OPAC] + b.colors_float[OPAC];
	result.colors_float[OPAC] = 1;
	return (result);
}

t_color	color_subtr(t_color minuend, t_color subtrahend)
{
	t_color result;

	result.colors_float[RED] = minuend.colors_float[RED] - \
								subtrahend.colors_float[RED];
	result.colors_float[GREEN] = minuend.colors_float[GREEN] - \
								subtrahend.colors_float[GREEN];
	result.colors_float[BLUE] = minuend.colors_float[BLUE] - \
								subtrahend.colors_float[BLUE];
	result.colors_float[OPAC] = minuend.colors_float[OPAC] - \
								subtrahend.colors_float[OPAC];
	result.colors_float[OPAC] = 1;
	return (result);
}

t_color	color_scale(float k, t_color a)
{
	t_color result;

	result.colors_float[RED] = a.colors_float[RED] * k;
	result.colors_float[GREEN] = a.colors_float[GREEN] * k;
	result.colors_float[BLUE] = a.colors_float[BLUE] * k;
	result.colors_float[OPAC] = a.colors_float[OPAC] * k;
	result.colors_float[OPAC] = 1;
	return (result);
}
void	convert_pixel_colors(t_color *color)
{
	if (color->colors_float[RED] < 0)
		color->colors_float[RED] = 0;
	if (color->colors_float[RED] > 1)
		color->colors_float[RED] = 1;
	if (color->colors_float[GREEN] < 0)
		color->colors_float[GREEN] = 0;
	if (color->colors_float[GREEN] > 1)
		color->colors_float[GREEN] = 1;
	if (color->colors_float[BLUE] < 0)
		color->colors_float[BLUE] = 0;
	if (color->colors_float[BLUE] > 1)
		color->colors_float[BLUE] = 1;
	color->colors_int[RED] = color->colors_float[RED] * 255;
	color->colors_int[GREEN] = color->colors_float[GREEN] * 255;
	color->colors_int[BLUE] = color->colors_float[BLUE] * 255;
	color->colors_int[OPAC] = 255;
}
