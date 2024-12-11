/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_fcts_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:21:04 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/11 22:46:24 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/utilities.h"

#include <math.h>

bool	is_in_range_int(int *num, int min, int max)
{
	if (*num <= max && *num >= min)
		return (true);
	else
		return (false);
}

void	exit_if_args_incompl(char **line_arr, int idx, char *message, \
								t_object *obj)
{
	if (line_arr[idx] == NULL)
		error_and_exit2(message, line_arr[0], obj);
	if (line_arr[idx][0] == '\n')
		error_and_exit2(message, line_arr[0], obj);
}

// bool	cam_inside_radius(t_object *cam, t_object *cy)
// {
// 	double		dist_to_axis;
// 	double		numerator;

// }

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
#include <stdio.h>
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
		// if (data->objects[pos]->identifier == CY)
		// {
		// 	cam_inside_radius(cam, data->objects[pos]);
		// 	cam_inside_height(cam, data->objects[pos]);
		// }
		if (data->objects[pos]->identifier == SP)
		{
			cam_inside_sphere(cam, data->objects[pos]);
		}
		pos++;
	}
printf("cam_inside? %d\n", cam->s_camera.is_inside_obj);
}
