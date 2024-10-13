/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:07:15 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/13 17:57:12 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "./includes/maths.h"
#include "./includes/miniRT.h"
#include "./MLX42/include/MLX42/MLX42.h"

#define WIDTH 1280
#define HEIGHT 720
#define TITLE "miniRT"

int	main (void)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	mlx = NULL;
	image = NULL;
	mlx = mlx_init(WIDTH, HEIGHT, TITLE, true);
	if (mlx == NULL)
		return (EXIT_FAILURE);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (image == NULL)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
		return (EXIT_FAILURE);
	fill_canvas(WIDTH, HEIGHT, image);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
