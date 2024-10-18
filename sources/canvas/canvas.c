/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:31:47 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/18 18:34:10 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../includes/miniRT.h"

void	fill_canvas(size_t width, size_t height)
{
	size_t			y_pixel;
	size_t			x_pixel;
	t_color			*color;
	t_ray			*ray;
	// t_img_plane	img_plane;
	// struct s_img_plane	img_plane;
	// t_tuple			pixel_pos;
	t_data			*data;

	data = get_data();
	// img_plane = data->objects[CAMERA].spec_membs.camera.img_plane;
	// img_plane = data->objects[CAMERA].s_camera.s_img_plane;
	y_pixel = 0;

// printf("address of image in fill_canvas: %p\n", data->image);
	while (y_pixel < height)
	{
		x_pixel = 0;
		while (x_pixel < width)
		{
// 			// pixel_pos = tuple_add(img_plane.origin, tuple_scale(x_pixel, img_plane.delta_x_vec));
// 			// pixel_pos = tuple_add(pixel_pos, tuple_scale(y_pixel, img_plane.delta_y_vec));
// 			// ray = create_ray(data->objects[CAMERA].position, pixel_pos);
			ray = create_ray(x_pixel, y_pixel);
// print_tuple(ray->direction_vec);
// printf("hitpt: %f\n", find_plane_hitpt(&data->objects[3], ray));
// printf("t for x:%zu , y:%zu : %f\n",x_pixel, y_pixel, find_plane_hitpt(data->objects[2], ray));

// 			// TODO: 	implement function to test for hitpoints of ray with plane
// 			//			test for all proper objects
// 			//			select correct hitpoint
// 			//			get color

			find_hit_pt(data->objects, ray);
			color = malloc(1 * sizeof(t_color));
			// color->colors[RED] = 255 * (1.0 * x_pixel / width);
			color->colors[RED] = 255 * (find_plane_hitpt(&data->objects[2], ray) - 15.0) / 8.0;
// printf("red: %d\n", color->colors[RED]);
			// color->colors[RED] = 0;
			color->colors[GREEN] = 0;
			color->colors[BLUE] = 0;
// 			// color.colors[BLUE] = 255 * (1.0 * y_pixel / height);
			color->colors[OPAC] = 255;
			mlx_put_pixel(data->image, x_pixel, y_pixel, find_hit_pt(data->objects, ray));
			// mlx_put_pixel(data->image, 0, 0, 0);
			// mlx_put_pixel(data->image, (uint32_t)x_pixel, (uint32_t)y_pixel, color->colors);
			free(color);
			x_pixel++;
		}
		y_pixel++;
	}
}

uint32_t	find_hit_pt(t_object *objects, t_ray *ray)
{
	float	hitpt1;
	float	hitpt2;

	// content = objects[2].spec_membs
	hitpt1 = find_plane_hitpt(objects + 2, ray);
	hitpt2 = find_plane_hitpt(objects + 3, ray);
// printf("hitpt1: %f, hitpt2: %f\n", hitpt1, hitpt2);
	if (hitpt1 < hitpt2)
		return (objects[2].s_plane.color.pixel_color);
	else
		return (objects[3].s_plane.color.pixel_color);
	return (0);			// change!
}
