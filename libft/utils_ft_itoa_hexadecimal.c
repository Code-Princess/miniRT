/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_itoa_hexadecimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:07:12 by llacsivy          #+#    #+#             */
/*   Updated: 2024/04/09 15:18:33 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_len(unsigned long n);

char	*ft_itoa_hexadecimal(unsigned int n)
{
	char			*resultstr;
	int				str_len;
	int				i;
	char			*hexadecimal_digits;

	hexadecimal_digits = "0123456789abcdef";
	str_len = n_len(n);
	resultstr = malloc(str_len + 1);
	if (resultstr == NULL)
		return (NULL);
	i = str_len - 1;
	if (n == 0)
		resultstr[i] = '0';
	while (n != 0)
	{
		resultstr[i--] = hexadecimal_digits[n % 16];
		n /= 16;
	}
	resultstr[str_len] = '\0';
	return (resultstr);
}

char	*ft_itoa_hexadecimal_upper(unsigned int n)
{
	char			*resultstr;
	int				str_len;
	int				i;
	char			*hexadecimal_digits;

	hexadecimal_digits = "0123456789ABCDEF";
	str_len = n_len(n);
	resultstr = malloc(str_len + 1);
	if (resultstr == NULL)
		return (NULL);
	i = str_len - 1;
	if (n == 0)
		resultstr[i] = '0';
	while (n != 0)
	{
		resultstr[i--] = hexadecimal_digits[n % 16];
		n /= 16;
	}
	resultstr[str_len] = '\0';
	return (resultstr);
}

char	*ft_itoa_hexadecimal_ptr(unsigned long n)
{
	char			*resultstr;
	int				str_len;
	int				i;
	char			*hexadecimal_digits;

	hexadecimal_digits = "0123456789abcdef";
	str_len = n_len(n);
	resultstr = malloc(str_len + 1);
	if (resultstr == NULL)
		return (NULL);
	i = str_len - 1;
	while (n != 0)
	{
		resultstr[i--] = hexadecimal_digits[n % 16];
		n /= 16;
	}
	resultstr[str_len] = '\0';
	return (resultstr);
}

static size_t	n_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}
