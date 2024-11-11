/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_fcts_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:03:30 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/11 16:28:13 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
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
	if(i)
	{
		
	}
}
void	init_color(t_object *obj, char **line_arr, int idx)
{
	
}