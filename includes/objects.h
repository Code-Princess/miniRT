/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:13:50 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/06 13:41:36 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "./maths.h"
# include "./ray.h"
# include "./color.h"

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
	double	ambient;
	double	diffuse;
	double	specular;
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
			double		angle;
			struct
			{
				t_tuple	origin;
				t_tuple	delta_x_vec;
				t_tuple	delta_y_vec;
			}		s_img_plane;
		}		s_camera;
		struct
		{
			double	brightness;
		}		s_amb_light;
		struct
		{
			double	brightness;
			t_color	intensity;
		}		s_light;
		struct
		{
			double	radius;
		}		s_sphere;
		struct
		{
			t_tuple	normal_vec;
		}		s_plane;
		struct
		{
			t_tuple	axis_vec;
			double	radius;
			double	height;
		}		s_cy;
	};
}	t_object;

typedef struct s_cy_help
{
	double	discr;
	double	a;
	double	b;
	double	c;
	double	t_1;
	double	t_2;
	t_tuple	v;
	t_tuple	v_a;
	t_tuple	delta_p;
	t_tuple	temp1;
	t_tuple	temp2;
}			t_cy_help;

typedef struct s_hit_obj
{
	t_object	*obj;
	double		t;
	t_tuple		hit_pt;
	t_tuple		normal_vec;
	bool		not_in_shadow;
	bool		obj_found;
}				t_hit_obj;

typedef double		(*t_hit_pt_ft_array)(t_object *object, t_ray *ray);
typedef t_tuple		(*t_get_normal_ft_array)(t_hit_obj *hit_obj, t_ray *ray);

t_object				create_plane(t_tuple position, t_color color, \
										t_tuple normal_vec);

t_hit_obj				find_hit_pt(t_object **objects, t_ray *ray);
t_hit_pt_ft_array		*get_hit_pt_ft(void);
t_get_normal_ft_array	*get_normal_vec_ft(void);
double					find_sphere_hitpt(t_object *sphere, t_ray *ray);
double					find_plane_hitpt(t_object *plane, t_ray *ray);
double					find_cylinder_hitpt(t_object *cylinder, t_ray *ray);
double					find_cylinder_lateral_hitpt(t_object *cy, \
										t_cy_help *cy_helper, t_ray *ray);
double					find_cylinder_base_hitpt(t_object *cy, t_ray *ray);
bool					pt_is_between_slabs(double t, t_ray *ray, \
											t_object *cylinder);
double					pt_is_on_top(t_ray *ray, t_object *cylinder);
double					pt_is_on_bottom(t_ray *ray, t_object *cylinder);

t_tuple					calc_sphere_normal_vec(t_hit_obj *hit_obj, t_ray *ray);
t_tuple					calc_plane_normal_vec(t_hit_obj *hit_obj, t_ray *ray);
t_tuple					calc_cylinder_normal_vec(t_hit_obj *hit_obj, \
													t_ray *ray);
t_tuple					calc_cylinder_lateral_normal_vec(t_hit_obj *cy, \
															t_ray *ray);

int						get_object_index(t_data *data, t_identifier identifier);

#endif
