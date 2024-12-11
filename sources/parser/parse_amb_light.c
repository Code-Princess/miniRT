/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_amb_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:51:34 by daspring          #+#    #+#             */
/*   Updated: 2024/12/11 20:37:11 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../includes/free.h"
#include "../../includes/utilities.h"
#include "../../libft/libft.h"

t_object	*parse_amb_light_input(char **line_arr)
{
	t_object			*amb_light;
	int					idx;
	static int			ambient_counter;
	// t_data				*data;

	// data = get_data();
	ambient_counter++;
	if (ambient_counter > 1)
		error_and_exit2("Too many ambient lights.", "A", NULL);
	amb_light = ft_calloc(1, sizeof(t_object));
	if (amb_light == NULL)
		error_and_exit2("Malloc failed.\n", "input", NULL);
	amb_light->obj_name = AMB_LIGHT;
	amb_light->identifier = A;
	idx = 1;
	init_brightness(amb_light, line_arr, idx);
	idx += 1;
	init_color(amb_light, line_arr, idx);
	return (amb_light);
}
