/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:04:01 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/06 13:07:30 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

typedef struct s_hit_obj	t_hit_obj;
typedef struct s_ray		t_ray;
typedef struct s_material	t_material;
typedef struct s_object		t_object;
typedef struct s_data		t_data;
typedef struct s_tuple		t_tuple;

typedef enum e_colors
{
	OPAC,
	BLUE,
	GREEN,
	RED
}	t_colors;

typedef struct	s_color
{
	float	colors_float[4];
	union
	{
		uint32_t	pixel_color;
		uint8_t		colors_int[4];
	};
}	t_color;

// typedef union u_color
// {
// 	uint32_t	pixel_color;
// 	uint8_t		colors[4];
// }	t_color;

t_color		set_color(float r, float g, float b, float opac);
// t_color		set_color(int r, int g, int b, int opac);
t_color		color_scale(float k, t_color a);
t_color		color_subtr(t_color minuend, t_color subtrahend);
t_color		color_add(t_color a, t_color b);
t_color		color_mult(t_color a, t_color b);
void		convert_pixel_colors(t_color *color);
void		prepare_color_calc(t_hit_obj *hit_obj, t_object *light, t_ray *ray);
uint32_t	calc_normal_color(t_hit_obj *hit_obj, t_ray *ray);
t_color		calc_ambient_color(t_hit_obj *hit_obj, t_object *light, t_ray *ray);
t_color		calc_diffuse_color(t_hit_obj *hit_obj, t_object *light, t_ray *ray);
t_color		calc_specular_color(t_hit_obj *hit_obj, t_object *light, t_ray *ray);
uint32_t	calc_pixel_color(t_hit_obj *hit_obj, t_ray *ray, t_data *data);
t_material	set_material(float ambient, float diffuse, float specular, int shininess);
t_tuple 	*calc_reflect_vec(t_tuple *incomming, t_tuple *normal_vec);
t_color		lighting(t_hit_obj *hit_obj, t_object *light, t_ray *ray);

#endif
