/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:31:47 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/14 22:15:53 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../includes/miniRT.h"

void	fill_canvas(int width, int height, t_data *data)
{
	int			y_pixel;
	int			x_pixel;
	t_color		color;
	t_ray		ray;
	t_img_plane	img_plane;
	t_tuple		pixel_pos;

	img_plane = data->objects[CAMERA].spec_membs.camera.img_plane;
	y_pixel = 0;
	while (y_pixel < height)
	{
		x_pixel = 0;
		while (x_pixel < width)
		{
			pixel_pos = tuple_add(img_plane.origin, tuple_scale(x_pixel, img_plane.delta_x_vec));
			pixel_pos = tuple_add(pixel_pos, tuple_scale(y_pixel, img_plane.delta_y_vec));
			ray = create_ray(data->objects[CAMERA].position, pixel_pos);

			// TODO: 	implement function to test for hitpoints of ray with plane
			//			test for all proper objects
			//			select correct hitpoint
			//			get color

			color.colors[RED] = 255 * (1.0 * x_pixel / width);
			// color.colors[RED] = 0;
			color.colors[GREEN] = 0;
			// color.colors[BLUE] = 0;
			color.colors[BLUE] = 255 * (1.0 * y_pixel / height);
			color.colors[OPAC] = 255;
			mlx_put_pixel(data->image, x_pixel, y_pixel, color.pixel_color);
			x_pixel++;
		}
		y_pixel++;
	}
}