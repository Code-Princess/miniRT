/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:13:50 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/26 19:47:58 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "maths.h"
# include "ray.h"
# include "color.h"

// typedef union u_color	t_color;

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

typedef struct s_material
{
	float	ambient;
	float	diffuse;
	float	specular;
	int		shininess;
}				t_material;

typedef struct s_object
{
	t_obj_name		obj_name;
	t_identifier	identifier;
	t_tuple			position;
	t_color			color;
	t_material		material;
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
			float	brightness;
		}		s_amb_light;
		struct
		{
			float	brightness;
			t_color	intensity;
		}		s_light;
		struct
		{
			float	radius;
		}		s_sphere;
		struct
		{
			t_tuple	normal_vec;
		}		s_plane;
		struct
		{
			t_tuple	axis_vec;
			float	radius;
			float	height;
		}		s_cy;
	};
}	t_object;

typedef struct s_cy_helper
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
}			t_cy_helper;

typedef struct s_hit_obj
{
	t_object	*obj;
	float		t;
	t_tuple		hit_pt;
	t_tuple		normal_vec;
	bool		not_in_shadow;
	bool		obj_found;
}				t_hit_obj;

typedef float		(*t_hit_pt_ft_array)(t_object *object, t_ray *ray);
typedef t_tuple		(*t_get_normal_ft_array)(t_hit_obj *hit_obj, t_ray *ray);

// void					init_camera(t_data *data);
// void					calc_image_plane(t_object *camera);
t_tuple					calc_origin(t_object *camera);
void					init_plane(t_data *data);
t_object				*create_plane(t_tuple position, t_color color, \
										t_tuple normal_vec);
t_object				create_plane2(t_tuple position, t_color color, t_tuple normal_vec);
void					init_sphere(t_data *data);
void					init_cylinder(t_data *data);
void					init_light(t_data *data);

t_hit_obj				find_hit_pt(t_object **objects, t_ray *ray);
t_hit_pt_ft_array		*get_hit_pt_ft(void);
t_get_normal_ft_array	*get_normal_vec_ft(void);
float					find_sphere_hitpt(t_object *sphere, t_ray *ray);
float					find_plane_hitpt(t_object *plane, t_ray *ray);
float					find_cylinder_hitpt(t_object *cylinder, t_ray *ray);
float					find_cylinder_lateral_hitpt(t_object *cy, t_cy_helper *cy_helper, t_ray *ray);
// float					find_cylinder_lateral_hitpt(t_object *cy, t_ray *ray);
float					find_cylinder_base_hitpt(t_object *cy, t_ray *ray);
int						pt_is_between_slabs(float t, t_ray *ray, \
											t_object *cylinder);
float					pt_is_on_top(t_ray *ray, t_object *cylinder);
float					pt_is_on_bottom(t_ray *ray, t_object *cylinder);

t_tuple					calc_sphere_normal_vec(t_hit_obj *hit_obj, t_ray *ray);
t_tuple					calc_plane_normal_vec(t_hit_obj *hit_obj, t_ray *ray);
t_tuple					calc_cylinder_normal_vec(t_hit_obj *hit_obj, \
													t_ray *ray);
t_tuple					calc_cylinder_lateral_normal_vec(t_hit_obj *cy, \
															t_ray *ray);

int						get_light_index(t_data *data);
int						get_object_index(t_data *data, t_identifier identifier);

#endif
