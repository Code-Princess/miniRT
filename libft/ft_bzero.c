/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:26:39 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/11 18:01:09 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*cast_s;

	cast_s = (char *)s;
	while (n > 0)
	{
		cast_s[n - 1] = 0;
		n--;
	}
	s = cast_s;
}

/* int	main(void)
{
	char	s1[] = "123456789";
	char	s2[] = "123456789";
	size_t	n;

	n = 3;
	printf("%s is the input string\n", s1);
	ft_bzero(s1, n);
	printf("%s is the output string of my ft_bzero\n", s1);
	bzero(s2, n);
	printf("%s is the output string of lib bzero\n", s2);
	return (0);
} */
