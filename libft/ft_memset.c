/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:53:03 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/11 18:03:22 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*cast_b;

	cast_b = (char *)b;
	while (len > 0)
	{
		cast_b[len - 1] = (unsigned char)c;
		len--;
	}
	return (cast_b);
}

/* int	main(void)
{
	char	c;
	size_t	len;
	char	b[] = "123456789hallo";

	c = 'X';
	len = 2;
	printf("%s is the input string\n", b);
	printf("%s is the output string of my ft_memset\n", ft_memset(b, c, len));
	printf("%s is the output string of libc memset\n", memset(b, c, len));
	return (0);
} */
