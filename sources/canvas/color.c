/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:42:09 by daspring          #+#    #+#             */
/*   Updated: 2024/11/27 13:51:01 by daspring         ###   ########.fr       */
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

t_color	color_subtr(t_color minuend, t_color subtrahend)
{
	t_color	result;

	result.colors_float[RED] = minuend.colors_float[RED] - \
								subtrahend.colors_float[RED];
	result.colors_float[GREEN] = minuend.colors_float[GREEN] - \
								subtrahend.colors_float[GREEN];
	result.colors_float[BLUE] = minuend.colors_float[BLUE] - \
								subtrahend.colors_float[BLUE];
	result.colors_float[OPAC] = minuend.colors_float[OPAC] - \
								subtrahend.colors_float[OPAC];
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
