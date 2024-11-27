/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fcts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:24:15 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/22 14:03:15 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../includes/objects.h"

void	free_char_ptr_array(char **ptr_array)
{
	int	pos;

	pos = 0;
	if (ptr_array != NULL)
	{
		while (ptr_array[pos] != NULL)
		{
			free(ptr_array[pos]);
			pos++;
		}
	}
	free(ptr_array);
	ptr_array = NULL;
}

void	free_obj_ptr_array(t_object **objs_array)
{
	int	pos;

	pos = 0;
	if (objs_array != NULL)
	{
		while (objs_array[pos] != NULL)
		{
			free(objs_array[pos]);
			pos++;
		}
	}
	free(objs_array);
	objs_array = NULL;
}
