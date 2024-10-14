/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:13:50 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/14 11:38:09 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "miniRT.h"

typedef enum e_identifier
{
	A,
	C,
	L,
	SP,
	PL,
	CY
}	t_identifier;

typedef enum e_obj_name
{
	AMB_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj_name;

typedef struct s_object
{
	t_obj_name		obj_name;
	t_identifier	identifier;
	t_tuple			coordinate;
	t_spec_membs	spec_membs;
}	t_object;

typedef union u_spec_membs
{
	t_amb_light	amb_light;
	t_camera	camera;
	t_light		light;
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_spec_membs;

typedef struct s_camera
{
	t_tuple		normal_vec;
	float		angle;
	t_img_plane	img_plane;
}		t_camera;

typedef struct s_amb_light
{
	t_color	color;
	float	brightness;
}		t_amb_light;

typedef struct s_light
{
	// t_color	color; unused in mandatory
	float	brightness;
}		t_light;

typedef struct s_sphere
{
	t_color	color;
	float	diameter;
}		t_sphere;

typedef struct s_plane
{
	t_color	color;
	t_tuple	normal_vec;
}		t_plane;

typedef struct s_cylinder
{
	t_color	color;
	t_tuple	normal_vec;
	float	diameter;
	float	height;
}		t_cylinder;

typedef struct s_img_plane
{
	t_tuple origin;
	t_tuple delta_x_vec;
	t_tuple delta_y_vec;
	int		pixel_x_count;
	int		pixel_y_count;
}		t_img_plane;
