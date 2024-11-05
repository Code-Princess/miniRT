/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:45:25 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/05 14:59:31 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../MLX42/include/MLX42/MLX42.h"

# include "maths.h"
# include "objects.h"
# include "color.h"
# include "ray.h"

# define WIDTH_IN_PIXEL 600
# define HEIGHT_IN_PIXEL 600
# define TITLE "miniRT"

# define CANVAS_WIDTH 10.0

typedef struct s_object	t_object;
typedef struct s_ray	t_ray;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_object	**objects;
	int			magic_number;
}		t_data;

t_data		*get_data(void);
void		init_data(t_data *data);
void		fill_canvas(size_t width, size_t height);

void		print_tuple(t_tuple tuple);
void		print_color(t_color color);

#endif
