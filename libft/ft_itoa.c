/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:07:12 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/15 15:23:15 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(long n);

char	*ft_itoa(int n)
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
	resultstr[0] = '0';
	if (long_n < 0)
		long_n *= -1;
	i = str_len - 1;
	while (long_n != 0)
	{
		resultstr[i] = (long_n % 10) + 48;
		long_n /= 10;
		i--;
	}
	if (n < 0)
		resultstr[0] = '-';
	resultstr[str_len] = '\0';
	return (resultstr);
}

static int	n_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
