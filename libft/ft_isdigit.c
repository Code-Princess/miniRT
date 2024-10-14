/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:15:14 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/06 13:46:55 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h>
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	char	c;

	c = 'h';
	if (ft_isdigit(c))
		printf("my ft_isdigit is true for the character: %c\n", c);
	else
		printf("my ft_isdigit is false for the character: %c\n", c);
	if (isdigit(c))
		printf("libc isdigit is true for the character: %c\n", c);
	else
		printf("libc isdigit is false for the character: %c\n", c);
	return (0);
} */
