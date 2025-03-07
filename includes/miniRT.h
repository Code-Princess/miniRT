/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:45:25 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/12 00:38:32 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../MLX42/include/MLX42/MLX42.h"

# include "maths.h"
# include "objects.h"
# include "color.h"
# include "ray.h"

# define WIDTH_IN_PIXEL 1234
# define HEIGHT_IN_PIXEL 789
# define TITLE "miniRT"

# define CANVAS_WIDTH 10.0

# define INFINI_FLOAT 1E-12
# define AMBIENT 0.2
# define MAX_RADIUS 2000
# define MAX_CY_HEIGHT 2000

typedef struct s_object	t_object;
typedef struct s_ray	t_ray;

typedef struct s_input
{
	int		line_count;
}				t_input;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_input		input;
	t_object	**objects;
	int			magic_number;
	char		*line;
	char		**line_array;
}		t_data;

t_data		*get_data(void);
void		handle_input(t_data *data, int argc, char **argv);
void		fill_canvas(t_data *data);
void		esc_hook(void *param);

void		print_tuple(t_tuple tuple);

#endif
