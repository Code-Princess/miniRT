/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:07:15 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/18 13:28:24 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "./includes/maths.h"
#include "./includes/miniRT.h"
#include "./MLX42/include/MLX42/MLX42.h"
#include "./libft/libft.h"

int	main (void)
{
	t_data		*data;

	data = get_data();
	init_data(data);
	data->mlx = NULL;
	data->image = NULL;
	data->mlx = mlx_init(WIDTH, HEIGHT, TITLE, true);
	if (data->mlx == NULL)
		return (EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->image == NULL)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
		return (EXIT_FAILURE);
	fill_canvas(WIDTH, HEIGHT);
	mlx_loop(data->mlx);
printf("still alive!\n");
	mlx_terminate(data->mlx);
	return (0);
}

void	init_data(t_data *data)
{
	data->objects = ft_calloc(10, sizeof(t_object)); // magic number used for num of array entries
	// error handling for malloc!
	init_camera(data);
	init_plane(data);
}

t_data	*get_data(void)
{
	static t_data data;

	return (&data);
}
