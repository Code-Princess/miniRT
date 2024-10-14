/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:42:47 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/12 10:48:30 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cast_dst;
	char	*cast_src;

	cast_dst = (char *)dst;
	cast_src = (char *)src;
	if (cast_dst == NULL && cast_src == NULL)
		return (dst);
	if (cast_dst <= cast_src)
	{
		while (len-- > 0)
		{
			*cast_dst++ = *cast_src++;
		}
	}
	else if (cast_dst > cast_src)
	{
		cast_dst = cast_dst + len - 1;
		cast_src = cast_src + len - 1;
		while (len > 0)
		{
			*cast_dst-- = *cast_src--;
			len--;
		}
	}
	return (dst);
}

/* int	main(void)
{
	size_t	len;

	char str1[] = "abcde";
	char str2[] = "abcde";
	char str3[] = "abcdefgh";
	char str4[] = "abcdefgh";
	char *dst1 = str1;
	char *dst2 = str2;
	char *dst3 = str3;
	char *dst4 = str4;
	
	len = 3;
	//lib memmove
	printf("%s is the input dst1\n", dst1);
	memmove(dst1 + 2, dst1, len);
	printf("%s is the output dst1 after lib memmove\n", dst1);
	//my ft_memmove
	printf("%s is the input dst2\n", dst2);
	ft_memmove(dst2 + 2, dst2, len);
	printf("%s is the output dst2 after my ft_memmove\n", dst2);
	
	len = 4;
	//lib memmove
	printf("%s is the input dst1\n", dst3);
	memmove(dst3 + 2, dst3, len);
	printf("%s is the output dst3 after lib memmove\n", dst3);
	//my ft_memmove
	printf("%s is the input dst4\n", dst4);
	ft_memmove(dst4 + 2, dst4, len);
	printf("%s is the output dst4 after my ft_memmove\n", dst4);
	return (0);
} */
