/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fcts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:24:15 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/22 13:24:34 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
