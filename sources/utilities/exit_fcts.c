/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fcts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:04:48 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/06 13:42:22 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../includes/miniRT.h"
#include "../../includes/free.h"
#include "../../includes/utilities.h"

void	error_and_exit(char *message, char *identifier)
{
	t_data	*data;

	data = get_data();
	ft_printf_error("Error\n");
	ft_printf_error("%s: %s\n", identifier, message);
	free_obj_ptr_array(data->objects);
	exit(1);
}

void	error_and_exit2(char *message, char *identifier, t_object *obj)
{
	t_data	*data;

	data = get_data();
	ft_printf_error("Error\n");
	ft_printf_error("%s: %s\n", identifier, message);
	free_obj_ptr_array(data->objects);
	free(obj);
	free_char_ptr_array(data->line_array);
	free(data->line);
	exit(1);
}
