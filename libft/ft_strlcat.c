/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:15:20 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/13 14:35:03 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_help(const char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen_help(src);
	dst_len = ft_strlen_help(dst);
	len = dst_len + src_len;
	if (dstsize <= dst_len)
	{
		len = src_len + dstsize;
		return (len);
	}
	while (dst_len < (dstsize - 1) && *src != '\0')
	{
		dst[dst_len] = *src++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (len);
}

static size_t	ft_strlen_help(const char *str)
{
	size_t	n;

	n = 0;
	while (*str != '\0')
	{
		str++;
		n++;
	}
	return (n);
}

/* int	main(void)
{
		// test ft_ft_strlen_help()
    char *src0;
    src0 = "abcdefg";
    printf("%zu is src_len of %s\n\n", ft_strlen_help(src0), src0);

	// lib strlcpy
    char dst1[] = "123456789";
    const char *src1;
    size_t dstsize1;
    size_t len_out1;
    src1 = "abcd";
    dstsize1 = 4;
    printf("Inputs: %s is dst, %s is src, %zu is dstsize.\n", dst1, src1,
		dstsize1);
    len_out1 = strlcat(dst1, src1, dstsize1);
    printf("Outputs after lib strlcat: %zu is the return value len_out,\
		%s is dst.\n\n", \
	len_out1, dst1);

    // my ft_strlcpy
    char dst11[] = "123456789";
    const char *src11;
    size_t dstsize11;
    size_t len_out11;
    src11 = "abcd";
    dstsize11 = 4;
    printf("Inputs: %s is dst, %s is src, %zu is dstsize.\n", dst11, src11,\
		dstsize11);
    len_out11 = ft_strlcat(dst11, src11, dstsize11);
    printf("Outputs after my ft_strlcat: %zu is the return value len_out, \
		%s is dst.\n\n", \
	len_out11, dst11);
    
	return (0);
} */
