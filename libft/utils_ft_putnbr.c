/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:27:48 by llacsivy          #+#    #+#             */
/*   Updated: 2024/04/09 15:18:17 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nbr, int *error_ptr)
{
	char	*str_nbr;
	int		str_len;

	if (nbr == 0)
	{
		ft_putchar('0', error_ptr);
		if (*error_ptr == -1)
			return (*error_ptr);
		return (1);
	}
	str_nbr = ft_itoa(nbr);
	if (str_nbr == NULL)
	{
		free(str_nbr);
		*error_ptr = -1;
		return (*error_ptr);
	}
	ft_putstr(str_nbr, error_ptr);
	if (*error_ptr == -1)
		return (free(str_nbr), *error_ptr);
	str_len = ft_strlen(str_nbr);
	free(str_nbr);
	return (str_len);
}

int	ft_putnbr_unsigned(unsigned int nbr, int *error_ptr)
{
	char	*str_nbr;
	int		str_len;

	if (nbr == 0)
	{
		ft_putchar('0', error_ptr);
		if (*error_ptr == -1)
			return (*error_ptr);
		return (1);
	}
	str_nbr = ft_itoa_unsigned(nbr);
	if (str_nbr == NULL)
	{
		free(str_nbr);
		*error_ptr = -1;
		return (*error_ptr);
	}
	ft_putstr(str_nbr, error_ptr);
	if (*error_ptr == -1)
		return (free(str_nbr), *error_ptr);
	str_len = ft_strlen(str_nbr);
	free(str_nbr);
	return (str_len);
}

int	ft_puthexadecnbr(int base10nbr, int *error_ptr)
{
	char	*str_nbr;
	int		str_len;

	if (base10nbr == 0)
	{
		ft_putchar('0', error_ptr);
		if (*error_ptr == -1)
			return (*error_ptr);
		return (1);
	}
	str_nbr = ft_itoa_hexadecimal(base10nbr);
	if (str_nbr == NULL)
	{
		free(str_nbr);
		*error_ptr = -1;
		return (*error_ptr);
	}
	ft_putstr(str_nbr, error_ptr);
	if (*error_ptr == -1)
		return (free(str_nbr), *error_ptr);
	str_len = ft_strlen(str_nbr);
	free(str_nbr);
	return (str_len);
}

int	ft_puthexadecnbr_upper(int base10nbr, int *error_ptr)
{
	char	*str_nbr;
	int		str_len;

	if (base10nbr == 0)
	{
		ft_putchar('0', error_ptr);
		if (*error_ptr == -1)
			return (*error_ptr);
		return (1);
	}
	str_nbr = ft_itoa_hexadecimal_upper(base10nbr);
	if (str_nbr == NULL)
	{
		free(str_nbr);
		*error_ptr = -1;
		return (*error_ptr);
	}
	ft_putstr(str_nbr, error_ptr);
	if (*error_ptr == -1)
		return (free(str_nbr), *error_ptr);
	str_len = ft_strlen(str_nbr);
	free(str_nbr);
	return (str_len);
}
