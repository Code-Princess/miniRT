/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:50:56 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/12 10:25:35 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cast_dst;
	char	*cast_src;

	cast_dst = (char *)dst;
	cast_src = (char *)src;
	if (cast_dst == NULL && cast_src == NULL)
		return (dst);
	while (n > 0)
	{
		*cast_dst++ = *cast_src++;
		n--;
	}
	return (dst);
}

/* int	main(void)
{
	size_t	n;

	char dst[] = "12345678";
	const char src[] = "Halloooooooooo";
	char dst2[] = "12345678";
	const char src2[] = "Halloooooooooo";
	
	char str3[] = "abcde";
	char str4[] = "abcde";
	char str7[] = "abjdefgh";
	char str8[] = "abjdefgh";
	char *dst3;
	char *dst4;
	char *dst7;
	char *dst8;

	
	dst3 = str3;
	dst4 = str4;
	dst7 = str7;
	dst8 = str8;
	
	char *dst5 = NULL;
	char *dst6 = NULL;

	n = 5;
	// lib memcpy
	printf("%s is the destination input\n", dst);
	memcpy(dst, src, n);
	printf("%s is the destination output after lib memcpy\n", dst);
	// my ft_memcpy
	printf("%s is the destination input\n", dst2);
	ft_memcpy(dst2, src2, n);
	printf("%s is the destination output after my ft_memcpy\n", dst2);
	
	// lib memcpy
	n = 3;
	printf("%s is the destination input\n", dst3);
	memcpy(dst3 + 2, dst3, n);
	printf("%s is the destination output after lib memcpy\n", dst3);
	// my ft_memcpy
	printf("%s is the destination input\n", dst4);
	ft_memcpy(str4 + 2, str4, n);
	printf("%s is the destination output after my ft_memcpy\n", dst4);
	// lib memcpy
	printf("%s is the destination input\n", dst5);
	memcpy(dst5, dst5, 3);
	printf("%s is the destination output after lib memcpy\n", dst5);
	// my ft_memcpy
	printf("%s is the destination input\n", dst6);
	ft_memcpy(dst6, dst6, 3);
	printf("%s is the destination output after my ft_memcpy\n", dst6);
	
	// lib memcpy
	n = 4;
	printf("%s is the destination input\n", dst7);
	memcpy(dst7 + 2, dst7, n);
	printf("%s is the destination output after lib memcpy\n", dst7);
	// my ft_memcpy
	printf("%s is the destination input\n", dst8);
	ft_memcpy(dst8 + 2, dst8, n);
	printf("%s is the destination output after my ft_memcpy\n", dst8);
	return (0);
} */
