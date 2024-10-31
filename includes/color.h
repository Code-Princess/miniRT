/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:04:01 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/31 17:12:46 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

typedef struct s_hit_obj	t_hit_obj;
typedef struct s_ray		t_ray;
typedef struct s_material	t_material;
typedef struct s_object		t_object;

typedef enum e_colors
{
	OPAC,
	BLUE,
	GREEN,
	RED
}	t_colors;

typedef union u_color
{
	uint32_t	pixel_color;
	uint8_t		colors[4];
}	t_color;

t_color		set_color(int r, int g, int b, int opac);
// uint32_t	calc_pixel_color(t_hit_obj *hit_obj, t_ray *ray);
uint32_t	calc_pixel_color(t_hit_obj *hit_obj, t_ray *ray, t_data *data);
t_material	set_material(float ambient, float diffuse, float specular, int shininess);
t_tuple 	calc_reflect_vec(t_hit_obj hit_obj, t_ray ray, t_tuple normal_vec);
t_color		lighting(t_hit_obj *hit_obj, t_object *light, t_ray *ray);

#endif
