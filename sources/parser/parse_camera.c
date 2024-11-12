/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:36:56 by daspring          #+#    #+#             */
/*   Updated: 2024/11/12 19:07:32 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/objects.h"
#include "../../includes/parser.h"

t_object	*parse_camera_input(char **line_arr)
{
	t_object	*camera;

	camera = ft_calloc(1, sizeof(t_object));
printf("alive in parse_camera_input\n");
	camera->obj_name = CAMERA;
	camera->identifier = C;
	init_position(camera, line_arr, 1);
	init_normal_vec(camera, line_arr, 4);
	init_angle(camera, line_arr, 7);
	init_image_plane(camera);
	// calc_image_plane(camera);
	return (camera);
}
