/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:42:01 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/11 18:04:57 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	char	c;

	c = '@';
	if (ft_isascii(c))
		printf("my ft_isascii is true for character: %c\n", c);
	else
		printf("my ft_isascii is false for character: %c\n", c);
	if (isascii(c))
		printf("libc isascii is true for character: %c\n", c);
	else
		printf("libc isascii is false for character: %c\n", c);
} */
