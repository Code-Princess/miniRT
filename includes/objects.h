/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:13:50 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/23 15:03:05 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "maths.h"
# include "ray.h"
# include "color.h"

typedef enum e_identifier
{
	A,
	C,
	L,
	SP,
	PL,
	CY,
}	t_identifier;

typedef enum e_obj_name
{
	AMB_LIGHT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	OBJECT_COUNT,
}	t_obj_name;

typedef struct s_object
{
	t_obj_name		obj_name;
	t_identifier	identifier;
	t_tuple			position;
	union
	{
		struct
		{
			t_tuple		normal_vec;
			float		angle;
			struct
			{
				t_tuple	origin;
				t_tuple	delta_x_vec;
				t_tuple	delta_y_vec;
			}		s_img_plane;
		}		s_camera;
		struct
		{
			t_color	color;
			float	brightness;
		}		s_amb_light;
		struct
		{
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
			t_tuple	axis_vec;
			float	diameter;
			float	height;
		}		s_cylinder;
	};
}	t_object;

typedef float (*hit_pt_ft)(t_object *object, t_ray *ray);

void		init_camera(t_data *data);
void		calc_image_plane(t_object *camera);
t_tuple		calc_origin(t_object *camera);
void		init_plane(t_data *data);
void		init_sphere(t_data *data);
void		init_cylinder(t_data *data);

uint32_t	find_hit_pt(t_object **objects, t_ray *ray);
hit_pt_ft	*get_hit_pt_ft(void);
float		find_sphere_hitpt(t_object *sphere, t_ray *ray);
float		find_plane_hitpt(t_object *plane, t_ray *ray);
float		find_cylinder_hitpt(t_object *cylinder, t_ray *ray);


#endif
