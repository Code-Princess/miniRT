/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_itoa_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:27:00 by llacsivy          #+#    #+#             */
/*   Updated: 2024/04/09 15:18:27 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(long n);

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*resultstr;
	long	long_n;
	int		str_len;
	int		i;

	long_n = n;
	str_len = n_len(long_n);
	resultstr = malloc(str_len + 1);
	if (resultstr == NULL)
		return (NULL);
	i = str_len - 1;
	if (long_n == 0)
		resultstr[i] = '0';
	while (long_n != 0)
	{
		resultstr[i] = (long_n % 10) + 48;
		long_n /= 10;
		i--;
	}
	resultstr[str_len] = '\0';
	return (resultstr);
}

static int	n_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
