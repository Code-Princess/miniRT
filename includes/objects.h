/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:13:50 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/15 17:46:39 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

#include "maths.h"
#include "ray.h"
#include "color.h"

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

// typedef struct s_img_plane
// {
// 	t_tuple origin;
// 	t_tuple delta_x_vec;
// 	t_tuple delta_y_vec;
// }		t_img_plane;
//
// typedef struct s_camera
// {
// 	t_tuple		normal_vec;
// 	float		angle;
// 	t_img_plane	img_plane;
// }		t_camera;
//
// typedef struct s_amb_light
// {
// 	t_color	color;
// 	float	brightness;
// }		t_amb_light;
//
// typedef struct s_light
// {
// 	// t_color	color; unused in mandatory
// 	float	brightness;
// }		t_light;
//
// typedef struct s_sphere
// {
// 	t_color	color;
// 	float	diameter;
// }		t_sphere;
//
// typedef struct s_plane
// {
// 	t_color	color;
// 	t_tuple	normal_vec;
// }		t_plane;
//
// typedef struct s_cylinder
// {
// 	t_color	color;
// 	t_tuple	normal_vec;
// 	float	diameter;
// 	float	height;
// }		t_cylinder;
//
// typedef union u_spec_membs
// {
// 	t_amb_light	amb_light;
// 	t_camera	camera;
// 	t_light		light;
// 	t_sphere	sphere;
// 	t_plane		plane;
// 	t_cylinder	cylinder;
// }	t_spec_membs;
//
// typedef struct s_object2
// {
// 	t_obj_name		obj_name;
// 	t_identifier	identifier;
// 	t_tuple			position;
// 	t_spec_membs	spec_membs;
// }	t_object2;



typedef struct s_object
{
	t_obj_name		obj_name;
	t_identifier	identifier;
	t_tuple			position;
	// t_spec_membs	spec_membs;
	union
	{

		struct
		{
			t_tuple		normal_vec;
			float		angle;
			struct
			{
				t_tuple origin;
				t_tuple delta_x_vec;
				t_tuple delta_y_vec;
			}		s_img_plane;
		}		s_camera;

		struct
		{
			t_color	color;
			float	brightness;
		}		s_amb_light;

		struct
		{
			// t_color	color; unused in mandatory
			float	brightness;
		}		s_light;

		struct
		{
			t_color	color;
			float	diameter;
		}		s_sphere;

		struct
		{
			t_color	color;
			t_tuple	normal_vec;
		}		s_plane;

		struct
		{
			t_color	color;
			t_tuple	normal_vec;
			float	diameter;
			float	height;
		}		s_cylinder;
	};
}	t_object;

#endif
