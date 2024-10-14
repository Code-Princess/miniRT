/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:55:10 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/06 13:45:56 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h>
 */
int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a'
			&& c <= 'z'))
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	char	c;

	c = '3';
	if (ft_isalnum(c))
		printf("my ft_isalnum is true for: %c\n", c);
	else
		printf("my ft_isalnum is false for: %c\n", c);
	if (isalnum(c))
		printf("libc isalnum is true for: %c\n", c);
	else
		printf("libc isalnum is false for: %c\n", c);
} */
