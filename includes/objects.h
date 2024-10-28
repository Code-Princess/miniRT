/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:13:50 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/28 13:59:03 by llacsivy         ###   ########.fr       */
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
			float	radius;
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
			struct
			{
				float	discr;
				float	a;
				float	b;
				float	c;
				float	t_1;
				float	t_2;
				t_tuple	*v;
				t_tuple	*v_a;
				t_tuple	*delta_p;
				t_tuple	*temp1;
				t_tuple	*temp2;
			};
		}		s_cy;
	};
}	t_object;

typedef struct s_hit_obj
{
	float		pt;
	t_object	*obj;
}				t_hit_obj;

typedef float	(*t_hit_pt_ft)(t_object *object, t_ray *ray);
typedef t_tuple	*(*t_get_normal_ft)(t_hit_obj *hit_obj, t_ray *ray);

void		init_camera(t_data *data);
void		calc_image_plane(t_object *camera);
t_tuple		calc_origin(t_object *camera);
void		init_plane(t_data *data);
void		init_sphere(t_data *data);
void		init_cylinder(t_data *data);

t_hit_obj	*find_hit_pt(t_object **objects, t_ray *ray);
// uint32_t	find_hit_pt(t_object **objects, t_ray *ray);
t_hit_pt_ft	*get_hit_pt_ft(void);
float		find_sphere_hitpt(t_object *sphere, t_ray *ray);
float		find_plane_hitpt(t_object *plane, t_ray *ray);
float		find_cylinder_hitpt(t_object *cylinder, t_ray *ray);

t_tuple		*calc_sphere_normal_vec(t_hit_obj *hit_obj, t_ray *ray);


#endif
