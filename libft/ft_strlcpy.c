/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:02:32 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/12 18:51:03 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_help(const char *str);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dstsize_without_nullterminator;

	src_len = ft_strlen_help(src);
	if (dstsize == 0)
		return (src_len);
	dstsize_without_nullterminator = dstsize - 1;
	while (dstsize_without_nullterminator > 0 && *src != '\0')
	{
		*dst++ = *src++;
		dstsize_without_nullterminator--;
	}
	*dst = '\0';
	return (src_len);
}

static size_t	ft_strlen_help(const char *str)
{
	size_t	n;

	n = 0;
	while (*str)
	{
		str++;
		n++;
	}
	return (n);
}

/* int main(void)
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
    len_out1 = strlcpy(dst1, src1, dstsize1);
    printf("Outputs after lib strlcpy: %zu is the return (value len_out,
		%s is dst.\n\n", len_out1, dst1));

    // my ft_strlcpy
    char dst11[] = "123456789";
    const char *src11;
    size_t dstsize11;
    size_t len_out11;
    src11 = "abcd";
    dstsize11 = 4;
    printf("Inputs: %s is dst, %s is src, %zu is dstsize.\n", dst11, src11,
		dstsize11);
    len_out11 = ft_strlcpy(dst11, src11, dstsize11);
    printf("Outputs after my ft_strlcpy: %zu is the return (value len_out,
		%s is dst.\n\n", len_out11, dst11);
    
     // lib strlcpy
    char dst2[] = "12345";
    const char *src2;
    size_t dstsize2;
    size_t len_out2;
    src2 = "abcdefg";
    dstsize2 = 2;
    printf("Inputs: %s is dst, %s is src, %zu is dstsize.\n", dst2, src2,
		dstsize2);
    len_out2 = strlcpy(dst2, src2, dstsize2);
    printf("Outputs after lib strlcpy: %zu is the return (value len_out,
		%s is dst.\n\n", len_out2, dst2));

    // my ft_strlcpy
    char dst21[] = "12345";
    const char *src21;
    size_t dstsize21;
    size_t len_out21;
    src21 = "abcdefg";
    dstsize21 = 2;
    printf("Inputs: %s is dst, %s is src, %zu is dstsize.\n", dst21, src21,
		dstsize21);
    len_out21 = strlcpy(dst21, src21, dstsize21);
    printf("Outputs after my ft_strlcpy: %zu is the return (value len_out,
		%s is dst.\n\n", len_out21, dst21));

    // lib strlcpy
    char dst3[] = "12345";
    const char *src3;
    size_t dstsize3;
    size_t len_out3;
    src3 = "abcdefg";
    dstsize3 = 3;
    printf("Inputs: %s is dst, %s is src, %zu is dstsize.\n", dst3, src3,
		dstsize3);
    len_out3 = strlcpy(dst3, src3, dstsize3);
    printf("Outputs after lib strlcpy: %zu is the return (value len_out,
		%s is dst.\n\n", len_out3, dst3);

     // my ft_strlcpy
    char dst31[] = "12345";
    const char *src31;
    size_t dstsize31;
    size_t len_out31;
    src31 = "abcdefg";
    dstsize31 = 3;
    printf("Inputs: %s is dst, %s is src, %zu is dstsize.\n", dst31, src31,
		dstsize31);
    len_out31 = strlcpy(dst31, src31, dstsize31);
    printf("Outputs after my ft_strlcpy: %zu is the return (value len_out,
		%s is dst.\n\n", len_out31, dst31));

    // lib strlcpy
    char dst4[] = "12345";
    const char *src4;
    size_t dstsize4;
    size_t len_out4;
    src4 = "abcdefg";
    dstsize4 = 3;
    printf("Inputs: %s is dst, %s is src, %zu is dstsize.\n", dst4, src4,
		dstsize4);
    len_out4 = strlcpy(dst4, src4, dstsize4);
    printf("Outputs after lib strlcpy: %zu is the return (value len_out,
		%s is dst.\n\n", len_out4, dst4));

     // my ft_strlcpy
    char dst41[] = "12345";
    const char *src41;
    size_t dstsize41;
    size_t len_out41;
    src41 = "abcdefg";
    dstsize41 = 3;
    printf("Inputs: %s is dst, %s is src, %zu is dstsize.\n", dst41, src41,
		dstsize41);
    len_out41 = strlcpy(dst41, src41, dstsize41);
    printf("Outputs after my ft_strlcpy: %zu is the return (value len_out,
		%s is dst.\n\n", len_out41, dst41));

     // lib strlcpy
    char dst5[] = "rrrrrr";
    const char *src5;
    size_t dstsize5;
    size_t len_out5;
    src5 = "";
    dstsize5 = 15;
    printf("Inputs: %s is dst, %s is src, %zu is dstsize.\n", dst5, src5,
		dstsize5);
    len_out5 = strlcpy(dst5, src5, dstsize5);
    printf("Outputs after lib strlcpy: %zu is the return (value len_out,
		%s is dst.\n\n", len_out5, dst5));

     // my ft_strlcpy
    char dst51[] = "rrrrrr";
    const char *src51;
    size_t dstsize51;
    size_t len_out51;
    src51 = "";
    dstsize51 = 15;
    printf("Inputs: %s is dst, %s is src, %zu is dstsize.\n", dst51, src51,
		dstsize51);
    len_out51 = strlcpy(dst51, src51, dstsize51);
    printf("Outputs after my ft_strlcpy: %zu is the return (value len_out,
		%s is dst.\n\n", len_out51, dst51));

     // lib strlcpy
    char dst6[] = "rrrrrr";
    const char *src6;
    size_t dstsize6;
    size_t len_out6;
    src6 = "1234";
    dstsize6 = 0;
    printf("Inputs: %s is dst, %s is src, %zu is dstsize.\n", dst6, src6,
		dstsize6);
    len_out6 = strlcpy(dst6, src6, dstsize6);
    printf("Outputs after lib strlcpy: %zu is the return (value len_out,
		%s is dst.\n\n", len_out6, dst6));

     // my ft_strlcpy
    char dst61[] = "rrrrrr";
    const char *src61;
    size_t dstsize61;
    size_t len_out61;
    src61 = "1234";
    dstsize61 = 0;
    printf("Inputs: %s is dst, %s is src, %zu is dstsize.\n", dst61, src61,
		dstsize61);
    len_out61 = strlcpy(dst61, src61, dstsize61);
    printf("Outputs after my ft_strlcpy: %zu is the return (value len_out,
		%s is dst.\n\n", len_out61, dst61));

    return (0);
} */