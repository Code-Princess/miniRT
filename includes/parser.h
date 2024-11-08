/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:53:40 by daspring          #+#    #+#             */
/*   Updated: 2024/11/08 19:07:10 by daspring         ###   ########.fr       */
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

#endif