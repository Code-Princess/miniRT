/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:36:56 by daspring          #+#    #+#             */
/*   Updated: 2024/11/08 19:05:10 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/objects.h"

t_object	*parse_camera_input(char **line)
{
	t_object	*camera;
	char		**position;
	char		**normal_vec;

	camera = ft_calloc(1, sizeof(t_object));
printf("alive in parse_camera_input\n");
	camera->obj_name = CAMERA;
	camera->identifier = C;
	position = ft_split(line[1], ',');
	camera->position = set_tuple(ft_atof(position[0]), \
								ft_atof(position[1]), \
								ft_atof(position[2]), PT);
	normal_vec = ft_split(line[2], ',');
	camera->s_camera.normal_vec = set_tuple(ft_atof(normal_vec[0]), \
											ft_atof(normal_vec[1]), \
											ft_atof(normal_vec[2]), PT);
	camera->s_camera.angle = ft_atof(line[3]);
	calc_image_plane(camera);
	return (camera);
}
