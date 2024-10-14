/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_putptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:02:53 by llacsivy          #+#    #+#             */
/*   Updated: 2024/04/09 15:18:04 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_error(int *error_ptr);

int	ft_putptr(unsigned long ptr, int *error_ptr)
{
	char			*str;
	char			*result_str;
	char			*hexadecimal_ptr;
	int				str_len;

	if (ptr == 0)
		return (ft_putstr("0x0", error_ptr));
	str = "0x";
	hexadecimal_ptr = ft_itoa_hexadecimal_ptr((unsigned long)ptr);
	if (hexadecimal_ptr == NULL)
		return (set_error(error_ptr), *error_ptr);
	result_str = ft_strjoin(str, hexadecimal_ptr);
	free(hexadecimal_ptr);
	if (result_str == NULL)
		return (set_error(error_ptr), *error_ptr);
	result_str[ft_strlen(result_str)] = '\0';
	ft_putstr(result_str, error_ptr);
	if (*error_ptr == -1)
		return (free(result_str), *error_ptr);
	str_len = ft_strlen(result_str);
	free(result_str);
	return (str_len);
}

static void	set_error(int *error_ptr)
{
	*error_ptr = -1;
}
