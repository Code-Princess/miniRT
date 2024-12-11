/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_fcts_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:21:04 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/11 21:30:27 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/utilities.h"

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
