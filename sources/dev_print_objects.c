/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_print_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:37:21 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/29 15:37:22 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../includes/objects.h"

void	print_camera(t_object *camera)
{
	printf("print camera:\n");
	printf("position: ");
	print_tuple(camera->position);
	printf("normal_vec: ");
	print_tuple(camera->s_camera.normal_vec);
	printf("angle: %f\n", camera->s_camera.angle);
	printf("origin: ");
	print_tuple(camera->s_camera.s_img_plane.origin);
	printf("delta_x_vec");
	print_tuple(camera->s_camera.s_img_plane.delta_x_vec);
	printf("delta_y_vec");
	print_tuple(camera->s_camera.s_img_plane.delta_y_vec);
}

void	print_plane(t_object *plane)
{
	printf("print plane:\n");
	printf("position: ");
	print_tuple(plane->position);
	printf("normal_vec: ");
	print_tuple(plane->s_plane.normal_vec);
	printf("color: ");
	print_color(plane->color);
}
