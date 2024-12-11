/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_fcts_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:21:04 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/12 00:26:54 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/utilities.h"
#include "../../includes/parser.h"
#include "../../libft/libft.h"

#include <math.h>

void	check_cylinder(t_data *data)
{
	int			pos;
	t_object	*rev_cy;
	t_tuple		temp;

	pos = 0;
	while (data->objects[pos] != NULL)
	{
		if (data->objects[pos]->identifier == CY)
		{
			if (data->objects[pos]->s_cy.top)
			{
				pos++;
				continue ;
			}
			rev_cy = ft_calloc(1, sizeof(t_object));
			*rev_cy = *data->objects[pos];
			temp = tuple_scale(rev_cy->s_cy.height, &rev_cy->s_cy.axis_vec);
			rev_cy->position = tuple_add(&rev_cy->position, &temp);
			rev_cy->s_cy.axis_vec = tuple_neg(&rev_cy->s_cy.axis_vec);
			rev_cy->s_cy.top = true;
			data->objects[get_last_index(data->objects)] = rev_cy;
		}
		pos++;
	}
}

void	cam_inside_cyl(t_object *cam, t_object *cy)
{
	if (cam_inside_radius(cam, cy) && cam_inside_height(cam, cy))
		cam->s_camera.is_inside_obj = true;
}

bool	cam_inside_height(t_object *cam, t_object *cy)
{
	t_tuple		temp1;
	double		numerator;
	double		denominator;
	double		t;

	temp1 = direction(&cam->position, &cy->position);
	numerator = tuple_dot(&temp1, &cy->s_cy.axis_vec);
	denominator = tuple_dot_self(&cy->s_cy.axis_vec);
	t = numerator / denominator;
	return (0 <= t && t <= cy->s_cy.height);
}

bool	cam_inside_radius(t_object *cam, t_object *cy)
{
	double		dist_to_axis;
	double		numerator;
	double		denominator;
	t_tuple		temp1;

	temp1 = direction(&cam->position, &cy->position);
	temp1 = tuple_cross(&cy->s_cy.axis_vec, &temp1);
	numerator = tuple_magni(&temp1);
	denominator = tuple_magni(&cy->s_cy.axis_vec);
	dist_to_axis = numerator / denominator;
	return (dist_to_axis <= cy->s_cy.radius);
}

void	check_camera(t_data *data)
{
	int			cam_idx;
	t_object	*cam;
	int			pos;

	cam_idx = get_object_index(data, C);
	cam = data->objects[cam_idx];
	pos = 0;
	while (data->objects[pos] != NULL)
	{
		if (data->objects[pos]->identifier == CY)
			cam_inside_cyl(cam, data->objects[pos]);
		else if (data->objects[pos]->identifier == SP)
			cam_inside_sphere(cam, data->objects[pos]);
		pos++;
	}
}
