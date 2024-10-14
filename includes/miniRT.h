/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:45:25 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/14 13:08:09 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "maths.h"
# include "objects.h"
# include "color.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH 1280
# define HEIGHT 720
# define TITLE "miniRT"

# define CANVAS_WIDTH 10

typedef struct s_data
{
	t_object	*objects;
}		t_data;

typedef struct s_ray
{
	t_tuple	eye_point;
	t_tuple	direction_vec;
}		t_ray;

// typedef union u_color
// {
// 	uint32_t	pixel_color;
// 	uint8_t		colors[4];
// }				t_color;

enum e_colors
{
	OPAC,
	BLUE,
	GREEN,
	RED
};

void	init_data(t_data *data);
void	init_camera(t_data *data);
void	calc_image_plane(t_object *camera);
t_tuple	calc_origin(t_object *camera);

t_ray	create_ray(t_tuple E, t_tuple d);
void	fill_canvas(int width, int height, mlx_image_t *image);

#endif
