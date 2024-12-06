/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:52:39 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/27 13:51:01 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/color.h"
#include "../../includes/objects.h"

t_material	set_material(double ambient, double diffuse, double specular, \
							int shininess)
{
	t_material	material;

	material.ambient = ambient;
	material.diffuse = diffuse;
	material.specular = specular;
	material.shininess = shininess;
	return (material);
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
