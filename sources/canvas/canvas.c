/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:31:47 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/23 15:08:46 by daspring         ###   ########.fr       */
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

	object_idx = 0;
	hit_pt_min[0] = 9999.0;
	hit_pt = 9999.0;
	hit_pt_min[1] = 2.0;
	while (objects[object_idx] != NULL)
	{
		if (objects[object_idx]->obj_name <= LIGHT)
		{
			object_idx++;
			continue ;
		}
		hit_pt = get_hit_pt_ft()[objects[object_idx]->obj_name](objects[object_idx], ray);
		if (hit_pt < hit_pt_min[0] && hit_pt >= 1)
		{
			hit_pt_min[0] = hit_pt;
			hit_pt_min[1] = object_idx;
		}
		object_idx++;
	}
	if (hit_pt_min[0] >= 1)
		return (objects[(int)hit_pt_min[1]]->s_sphere.color.pixel_color);
	else
		return (0);
}

hit_pt_ft	*get_hit_pt_ft(void)
{
	static const hit_pt_ft	hit_pt_func[OBJECT_COUNT] = {
		[PLANE] = &find_plane_hitpt,
		[SPHERE] = &find_sphere_hitpt,
		[CYLINDER] = &find_cylinder_hitpt,
	};

	return (hit_pt_ft *)(hit_pt_func);
}

