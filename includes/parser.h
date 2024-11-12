/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:53:40 by daspring          #+#    #+#             */
/*   Updated: 2024/11/12 19:07:10 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "objects.h"

typedef t_object	*(*t_get_parse_ft_array)(char **line);

t_object				*parse_amb_light_input(char **line);
t_object				*parse_camera_input(char **line);
t_get_parse_ft_array	*get_parse_ft(void);
void					populate_objects_array(t_data *data, char **argv);
void					init_identifier(t_object *obj, char **line_arr, int idx);
void					init_brightness(t_object *obj, char **line_arr, int idx);
void					init_color(t_object *obj, char **line_arr, int idx);
void					init_position(t_object *obj, char **line_arr, int idx);
void					init_normal_vec(t_object *obj, char **line_arr, int idx);
void					init_image_plane(t_object *camera);
void					init_angle(t_object *obj, char **line_arr, int idx);


#endif