/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:23:48 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/06 13:46:39 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h>
 */
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/* int	main(void)
{
	char	c;

	c = 'p';
	if (ft_isalpha(c))
		printf("my ft_isalpha is true for the character %c\n", c);
	else
		printf("my ft_isalpha is false for the character %c\n", c);
	if (isalpha(c))
		printf("libc isalpha is true for the character %c\n", c);
	else
		printf("libc isalpha is false for the character %c\n", c);
	return (0);
} */
