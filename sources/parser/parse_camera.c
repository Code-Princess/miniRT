/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:36:56 by daspring          #+#    #+#             */
/*   Updated: 2024/11/13 19:46:03 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/objects.h"
#include "../../includes/parser.h"

t_object	*parse_camera_input(char **line_arr)
{
	t_object	*camera;
	int			idx;
	static int	camera_counter;

	camera_counter++;
	if (camera_counter > 1)
		; // error!
	camera = ft_calloc(1, sizeof(t_object));
	camera->obj_name = CAMERA;
	camera->identifier = C;
	idx = 1;
	init_position(camera, line_arr, idx);
	idx += 3;
	init_normal_vec(camera, line_arr, idx);
	idx += 3;
	init_angle(camera, line_arr, idx);
	init_image_plane(camera);
	return (camera);
}
