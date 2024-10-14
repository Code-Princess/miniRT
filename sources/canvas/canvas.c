/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:31:47 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/14 16:41:12 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../includes/miniRT.h"

void	fill_canvas(int width, int height, mlx_image_t *image)
{
	int			y_pixel;
	int			x_pixel;
	t_color		color;

	y_pixel = 0;
	while (y_pixel < height)
	{
		x_pixel = 0;
		while (x_pixel < width)
		{
			color.colors[RED] = 255 * (1.0 * x_pixel / width);
			// color.colors[RED] = 0;
			color.colors[GREEN] = 0;
			// color.colors[BLUE] = 0;
			color.colors[BLUE] = 255 * (1.0 * y_pixel / height);
			color.colors[OPAC] = 255;
			mlx_put_pixel(image, x_pixel, y_pixel, color.pixel_color);
			x_pixel++;
		}
		y_pixel++;
	}
}