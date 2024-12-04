/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:36:56 by daspring          #+#    #+#             */
/*   Updated: 2024/12/04 15:40:16 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../includes/free.h"
#include "../../includes/utilities.h"

t_object	*parse_camera_input(char **line_arr)
{
	t_object	*camera;
	int			idx;
	static int	camera_counter;
	t_data				*data;

	data = get_data();
	camera_counter++;
	if (camera_counter > 1)
	{
		free_char_ptr_array(line_arr);
		free (data->line);
		print_error_and_exit2("Too many cameras.", "C");
	}
	camera = ft_calloc(1, sizeof(t_object));
	if (camera == NULL)
		print_error_and_exit2("Malloc failed.\n", "input: ");
	camera->obj_name = CAMERA;
	camera->identifier = C;
	idx = 1;
	init_position(camera, line_arr, idx);
	idx += 3;
	init_normal_vec(camera, line_arr, idx);
	idx += 3;
	init_angle(camera, line_arr, idx);
	init_image_plane(camera);
// print_camera(camera);
	return (camera);
}
