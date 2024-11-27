/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:36:56 by daspring          #+#    #+#             */
/*   Updated: 2024/11/27 18:20:02 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../includes/utilities.h"

t_object	*parse_camera_input(char **line_arr)
{
	t_object	*camera;
	int			idx;
	static int	camera_counter;

	camera_counter++;
	if (camera_counter > 1)
	{
		print_error_and_exit2("Too many cameras.", "C");
	}
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
print_camera(camera);
	return (camera);
}
