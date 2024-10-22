/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:55:05 by daspring          #+#    #+#             */
/*   Updated: 2024/10/22 16:21:33 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"
#include "../includes/objects.h"

void	init_cylinder(t_data *data)
{
	t_object	*cylinder;

	cylinder = malloc(1 * sizeof(t_object));
	cylinder->obj_name = CYLINDER;
	cylinder->identifier = CY;
	cylinder->position = set_tuple(0, 0, 20, PT);
	cylinder->s_cylinder.color = set_color(100, 0, 150, 255);
	cylinder->s_cylinder.axis_vec = set_tuple(1.0, 1.0, 0, VEC);
	cylinder->s_cylinder.diameter = 20.0;
	cylinder->s_cylinder.height = 7.0;
	data->objects[6] = cylinder;
}

// float	find_cylinder_hitpt(t_object *sphere, t_ray *ray)
// {
// 	return();
// }