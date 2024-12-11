/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_fcts_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:21:04 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/12 00:24:11 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
// #include "../../includes/utilities.h"
// #include "../../includes/parser.h"

#include <math.h>

void	cam_inside_sphere(t_object *cam, t_object *sphere)
{
	double	squ_dist_to_center;
	t_tuple	pos_sp;
	t_tuple	pos_cam;

	pos_sp = sphere->position;
	pos_cam = cam->position;
	squ_dist_to_center = pow(pos_sp.x - pos_cam.x, 2) + \
						pow(pos_sp.y - pos_cam.y, 2) + \
						pow(pos_sp.z - pos_cam.z, 2);
	if (squ_dist_to_center <= pow(sphere->s_sphere.radius, 2))
	{
		cam->s_camera.is_inside_obj = true;
	}
}
