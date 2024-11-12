/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_fcts_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:03:30 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/12 15:11:42 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../libft/libft.h"

int	get_obj_name(char *identifier)
{
	if (ft_strcmp(identifier, "A") == 0)
		return (AMB_LIGHT);
	if (ft_strcmp(identifier, "C") == 0)
		return (CAMERA);
	if (ft_strcmp(identifier, "L") == 0)
		return (LIGHT);
	if (ft_strcmp(identifier, "sp") == 0)
		return (SPHERE);
	if (ft_strcmp(identifier, "pl") == 0)
		return (PLANE);
	if (ft_strcmp(identifier, "cy") == 0)
		return (CYLINDER);
	exit (-1); // proper error management missing!
}

void	init_brightness(t_object *obj, char **line_arr, int idx)
{
	float	brightness;
	brightness = ft_atof(line_arr[idx]);
	if (is_in_range(&brightness, 0, 1))
	{
		obj->s_amb_light.brightness = brightness;
	}
	else ;
		//error
}
void	init_color(t_object *obj, char **line_arr, int idx)
{
	t_color	color;
	int	red_col;
	int	green_col;
	int	blue_col;
	int	error;

	error = 0;
	red_col = ft_atoi_mod(line_arr[idx], &error);
	green_col = ft_atoi_mod(line_arr[idx + 1], &error);
	blue_col = ft_atoi_mod(line_arr[idx + 2], &error);
	if (is_in_range(&red_col, 0, 255) && is_in_range(&green_col, 0, 255) && \
		is_in_range(&blue_col, 0, 255) && error == 0)
	{
		obj->color = set_color(red_col / 255, green_col / 255, \
								blue_col / 255, 1);
	}
	else ;
		//error!
}

bool is_in_range(void *num, int min, int max)
{
	float	*number;

	number = (float *)num;
	if (*number <= (float)max && *number >= (float)min)
		return (true);
	else
		return (false);
}
