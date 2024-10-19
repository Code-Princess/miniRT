/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:45:25 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/19 14:17:36 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../MLX42/include/MLX42/MLX42.h"

# include "maths.h"
# include "objects.h"
# include "color.h"
# include "ray.h"

# define WIDTH 500
# define HEIGHT 500
# define TITLE "miniRT"

# define CANVAS_WIDTH 10.0

typedef struct s_object t_object;
typedef struct s_ray t_ray;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_object	**objects;
	int			magic_number;
}		t_data;

t_data	*get_data(void);

void	init_data(t_data *data);
void	init_camera(t_data *data);
void	calc_image_plane(t_object *camera);
t_tuple	calc_origin(t_object *camera);

void	fill_canvas(size_t width, size_t height);

void	init_plane(t_data *data);

uint32_t	find_hit_pt(t_object **objects, t_ray *ray);


void	print_tuple(t_tuple tuple);

#endif
