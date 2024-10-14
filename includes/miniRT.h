/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:45:25 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/14 22:10:01 by linda            ###   ########.fr       */
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
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_object	*objects;
}		t_data;

typedef struct s_ray
{
	t_tuple	eye_point;
	t_tuple	direction_vec;
}		t_ray;

void	init_data(t_data *data);
void	init_camera(t_data *data);
void	calc_image_plane(t_object *camera);
t_tuple	calc_origin(t_object *camera);

t_ray	create_ray(t_tuple E, t_tuple P);
void	fill_canvas(int width, int height, t_data *data);

void	init_plane(t_data *data);


#endif
