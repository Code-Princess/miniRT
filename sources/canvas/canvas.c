/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:31:47 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/19 15:00:33 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "../../MLX42/include/MLX42/MLX42.h"
#include "../../includes/miniRT.h"

// TODO: 	implement function to test for hitpoints of ray with plane
//			test for all proper objects
//			select correct hitpoint
//			get color
void	fill_canvas(size_t width, size_t height)
{
	size_t			y_pixel;
	size_t			x_pixel;
	t_ray			*ray;
	t_data			*data;

	data = get_data();
	y_pixel = 0;
	while (y_pixel < height)
	{
		x_pixel = 0;
		while (x_pixel < width)
		{
			ray = create_ray(x_pixel, y_pixel);
			mlx_put_pixel(data->image, x_pixel, y_pixel, \
							find_hit_pt(data->objects, ray));
			x_pixel++;
		}
		y_pixel++;
	}
}

uint32_t	find_hit_pt(t_object **objects, t_ray *ray)
{
	float	hit_pt;
	float	hit_pt_min[2];
	int		object_idx;

	object_idx = 2;
	hit_pt_min[0] = 9999.9;
	hit_pt_min[1] = -1.0;
	while (objects[object_idx] != NULL)
	{
		hit_pt = find_plane_hitpt(objects[object_idx], ray);
// printf("hit_pt for plane %d: %f\n", object_idx, hit_pt);
		if (hit_pt < hit_pt_min[0] && hit_pt > 0)
		{
			hit_pt_min[0] = hit_pt;
			hit_pt_min[1] = object_idx;
		}
		object_idx++;
	}
	return (objects[(int)hit_pt_min[1]]->s_plane.color.pixel_color);
}
