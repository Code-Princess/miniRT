/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:07:15 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/29 17:44:43 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "./includes/maths.h"
#include "./includes/miniRT.h"
#include "./includes/free.h"
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
	free_obj_ptr_array(data->objects);
	return (0);
}

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}
