/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:07:23 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/11 17:31:34 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	char	c;

	c = 0;
	if (ft_isprint(c))
		printf("my ft_isprint is true for the character: %c\n", c);
	else
		printf("my ft_isprint is false for the character: %c\n", c);
	if (isprint(c))
		printf("libc isprint is true for the character: %c\n", c);
	else
		printf("libc isprint is false for the character: %c\n", c);
	return (0);
} */
