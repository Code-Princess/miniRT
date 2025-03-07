/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:53:40 by daspring          #+#    #+#             */
/*   Updated: 2024/12/12 00:27:44 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "objects.h"

typedef t_object	*(*t_get_parse_ft_array)(char **line);

t_get_parse_ft_array	*get_parse_ft(void);
t_object				*parse_amb_light_input(char **line);
t_object				*parse_camera_input(char **line);
t_object				*parse_light_input(char **line_arr);
t_object				*parse_plane_input(char **line_arr);
t_object				*parse_cylinder_input(char **line_arr);
t_object				*parse_sphere_input(char **line_arr);
void					populate_objects_array(t_data *data, char **argv);
void					init_brightness(t_object *obj, char **line_arr, \
										int idx);
void					init_color(t_object *obj, char **line_arr, int idx);
void					init_position(t_object *obj, char **line_arr, int idx);
void					init_normal_vec(t_object *obj, char **line_arr, \
										int idx);
void					check_plane_normal_vec_dir(t_data *data);
void					check_completeness(t_data *data);
void					check_cylinder(t_data *data);
void					check_camera(t_data *data);
int						get_last_index(t_object **objects_array);
void					cam_inside_sphere(t_object *cam, t_object *sphere);
void					cam_inside_cyl(t_object *cam, t_object *cy);
bool					cam_inside_radius(t_object *cam, t_object *cy);
bool					cam_inside_height(t_object *cam, t_object *cy);
void					init_image_plane(t_object *camera);
void					init_angle(t_object *obj, char **line_arr, int idx);
void					init_radius(t_object *obj, char **line_arr, int idx);
void					init_height(t_object *obj, char **line_arr, int idx);
void					init_axis_vec(t_object *obj, char **line_arr, \
										int idx);
void					exit_if_args_incompl(char **line_arr, int idx, \
												char *message, t_object *obj);

#endif