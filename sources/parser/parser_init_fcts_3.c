/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_fcts_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:21:04 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/06 13:42:22 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"
#include "../../includes/maths.h"
#include "../../includes/utilities.h"
#include "../../libft/libft.h"

void	init_height(t_object *obj, char **line_arr, int idx)
{
	double	height;
	char	message[100];
	int		error;

	error = 0;
	exit_if_args_incompl(line_arr, idx, "height: missing argument", obj);
	height = ft_atof_mod(line_arr[idx], &error);
	if (is_in_range_float(&height, 0, MAX_CY_HEIGHT) && error == 0)
	{
		obj->s_cy.height = height;
	}
	else
	{
		ft_bzero(message, 100);
		ft_strlcat(message, "height: value not in range [0,", 100);
		ft_strlcat(message, ft_itoa(MAX_CY_HEIGHT), 100);
		ft_strlcat(message, "]", 100);
		error_and_exit2(message, line_arr[0], obj);
	}
}

void	check_completeness(t_data *data)
{
	char	completeness_str[4];
	int		pos;

	pos = 0;
	while (data->objects[pos] != NULL)
	{
		if (data->objects[pos]->identifier == C)
		{
			completeness_str[0] = 'C';
		}
		else if (data->objects[pos]->identifier == A)
		{
			completeness_str[1] = 'A';
		}
		else if (data->objects[pos]->identifier == L)
		{
			completeness_str[2] = 'L';
		}
		pos++;
	}
	if (ft_strcmp(completeness_str, "CAL") != 0)
		error_and_exit("C, A or L missing", "objects");
}

bool	is_in_range_int(int *num, int min, int max)
{
	if (*num <= max && *num >= min)
		return (true);
	else
		return (false);
}

void	exit_if_args_incompl(char **line_arr, int idx, char *message, \
								t_object *obj)
{
	if (line_arr[idx] == NULL)
		error_and_exit2(message, line_arr[0], obj);
	if (line_arr[idx][0] == '\n')
		error_and_exit2(message, line_arr[0], obj);
}
