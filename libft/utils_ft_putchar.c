/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_putchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:34:45 by llacsivy          #+#    #+#             */
/*   Updated: 2024/04/09 15:18:22 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c, int *error_ptr)
{
	if (write(1, &c, 1) == -1)
	{
		*error_ptr = -1;
		return (*error_ptr);
	}
	return (1);
}

int	ft_putstr(char *str, int *error_ptr)
{
	int	char_counter;

	char_counter = 0;
	if (str == NULL)
		str = "(null)";
	while (*str != '\0')
	{
		ft_putchar(*str, error_ptr);
		if (*error_ptr == -1)
			return (*error_ptr);
		str++;
		char_counter++;
	}
	return (char_counter);
}

int	ft_putpercent(int *error_ptr)
{
	ft_putchar('%', error_ptr);
	if (*error_ptr == -1)
		return (*error_ptr);
	return (1);
}
