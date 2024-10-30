/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:42:09 by daspring          #+#    #+#             */
/*   Updated: 2024/10/30 18:00:17 by daspring         ###   ########.fr       */
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
