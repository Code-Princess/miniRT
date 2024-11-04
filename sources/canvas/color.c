/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:42:09 by daspring          #+#    #+#             */
/*   Updated: 2024/11/04 16:51:56 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/color.h"
#include "../../includes/objects.h"

t_color	set_color(int r, int g, int b, int opac)
{
	t_color	color;

	color.colors[RED] = r;
	color.colors[GREEN] = g;
	color.colors[BLUE] = b;
	color.colors[OPAC] = opac;
	return (color);
}

t_material	set_material(float ambient, float diffuse, float specular, int shininess)
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

	result.colors[RED] = a.colors[RED] * b.colors[RED] / 255;
	result.colors[GREEN] = a.colors[GREEN] * b.colors[GREEN] / 255;
	result.colors[BLUE] = a.colors[BLUE] * b.colors[BLUE] / 255;
	result.colors[OPAC] = a.colors[OPAC] * b.colors[OPAC] / 255;
	return (result);
}

t_color	color_add(t_color a, t_color b)
{
	t_color result;

	result.colors[RED] = a.colors[RED] + b.colors[RED];
	result.colors[GREEN] = a.colors[GREEN] + b.colors[GREEN];
	result.colors[BLUE] = a.colors[BLUE] + b.colors[BLUE];
	result.colors[OPAC] = a.colors[OPAC] + b.colors[OPAC];
	return (result);
}

t_color	color_subtr(t_color minuend, t_color subtrahend)
{
	t_color result;

	result.colors[RED] = minuend.colors[RED] - subtrahend.colors[RED];
	result.colors[GREEN] = minuend.colors[GREEN] - subtrahend.colors[GREEN];
	result.colors[BLUE] = minuend.colors[BLUE] - subtrahend.colors[BLUE];
	result.colors[OPAC] = minuend.colors[OPAC] - subtrahend.colors[OPAC];
	return (result);
}

t_color	color_scale(float k, t_color a)
{
	t_color result;

	result.colors[RED] = a.colors[RED] * k;
	result.colors[GREEN] = a.colors[GREEN] * k;
	result.colors[BLUE] = a.colors[BLUE] * k;
	result.colors[OPAC] = a.colors[OPAC] * k;
	return (result);
}
