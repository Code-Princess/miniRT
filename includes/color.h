/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:04:01 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/06 13:16:54 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>
# include <stdbool.h>

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

typedef struct s_color
{
	double	colors_float[4];
	union
	{
		uint32_t	pixel_color;
		uint8_t		colors_int[4];
	};
}	t_color;

t_color		set_color(double r, double g, double b, double opac);
t_color		color_scale(double k, t_color a);
t_color		color_add(t_color a, t_color b);
t_color		color_mult(t_color a, t_color b);
void		convert_pixel_colors(t_color *color);
void		prepare_color_calc(t_hit_obj *hit_obj, t_ray *ray);
uint32_t	calc_normal_color(t_hit_obj *hit_obj, t_ray *ray);
t_color		calc_ambient_color(t_hit_obj *hit_obj, t_object *light);
t_color		calc_diffuse_color(t_hit_obj *hit_obj, t_object *light);
t_color		calc_specular_color(t_hit_obj *hit_obj, t_object *light, \
								t_ray *ray);
uint32_t	calc_pixel_color(t_hit_obj *hit_obj, t_ray *ray, t_data *data);
t_material	set_material(double ambient, double diffuse, double specular, \
						int shininess);
t_tuple		calc_reflect_vec(t_tuple *incomming, t_tuple *normal_vec);
bool		pt_is_in_shadow(t_object **objects, t_ray *ray);
void		is_in_shadow(t_object *light, t_hit_obj *hit_obj);

#endif
