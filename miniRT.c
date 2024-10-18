/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:07:15 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/18 18:28:48 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "./includes/maths.h"
#include "./includes/miniRT.h"
#include "./MLX42/include/MLX42/MLX42.h"
#include "./libft/libft.h"

int	main(void)
{
	t_data		*data;

	data = get_data();
	init_data();
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx_init(WIDTH, HEIGHT, TITLE, true);
	if (data->mlx == NULL)
		return (EXIT_FAILURE);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->image == NULL)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
		return (EXIT_FAILURE);
	fill_canvas(WIDTH, HEIGHT);

// mlx_put_pixel(data->image, 0, 0, 0);

// printf("still alive!\n");
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (0);
}

// int	main(void)
// {
// 	mlx_t		*mlx;
// 	mlx_image_t	*image;

// 	mlx = mlx_init(WIDTH, HEIGHT, TITLE, true);
// 	image = mlx_new
// 	return (0);
// }


// void	init_data(t_data *data)
void	init_data(void)
{
	t_data *data = get_data();

	data->objects = ft_calloc(10, sizeof(t_object)); // magic number used for num of array entries
	// error handling for malloc!
	init_camera(data);
	init_plane(data);
}

t_data	*get_data(void)
{
	static  t_data	data;

	return (&data);
}
