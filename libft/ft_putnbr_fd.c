/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:02:43 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/15 19:55:10 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	long long int	longlong_n;

	longlong_n = n;
	if (longlong_n < 0)
	{
		write(fd, "-", 1);
		longlong_n *= -1;
	}
	if (longlong_n >= 10)
	{
		ft_putnbr_fd(longlong_n / 10, fd);
		ft_putnbr_fd(longlong_n % 10, fd);
	}
	else
	{
		c = longlong_n + '0';
		write(fd, &c, 1);
	}
}
