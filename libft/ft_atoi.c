/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:19:43 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/13 13:26:55 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace_help(int c);
static int	ft_isdigit_help(int c);

int	ft_atoi(const char *str)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	while (ft_isspace_help(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit_help(*str))
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	number *= sign;
	return (number);
}

int	ft_atoi_mod(const char *str, int *error)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	while (ft_isspace_help(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit_help(*str))
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	if (!ft_isdigit_help(*str) && *str != '\0' && *str != '\n')
		*error = 1;
	number *= sign;
	return (number);
}

static int	ft_isspace_help(int c)
{
	char	cast_c;

	cast_c = (char)c;
	if (cast_c == '\t' || cast_c == '\n' || cast_c == '\v' || cast_c == '\f'\
	|| cast_c == '\r' || cast_c == 32)
		return (1);
	else
		return (0);
}

static int	ft_isdigit_help(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
