/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:07:15 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/12 19:09:30 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "./includes/maths.h"
#include "./includes/miniRT.h"
#include "./MLX42/include/MLX42/MLX42.h"
#include "./libft/libft.h"

int	main(int argc, char **argv)
{
	t_data		*data;

	data = get_data();
handle_input(data, argc, argv);


	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx_init(WIDTH_IN_PIXEL, HEIGHT_IN_PIXEL, TITLE, true);
	if (data->mlx == NULL)
		return (EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH_IN_PIXEL, HEIGHT_IN_PIXEL);
	if (data->image == NULL)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
		return (EXIT_FAILURE);
	fill_canvas(WIDTH_IN_PIXEL, HEIGHT_IN_PIXEL);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (0);
}

// void	init_data(t_data *data)
// {
// printf("init_data: data->input.line_count: %d\n", data->input.line_count);
// 	data->objects = ft_calloc(data->input.line_count, sizeof(t_object *));
// 	// error handling for malloc!
// 	// init_camera(data);
// 	init_plane(data);
// 	init_sphere(data);
// 	init_cylinder(data);
// 	init_light(data);
// }
// printf("still alive in init_data!\n");

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}
