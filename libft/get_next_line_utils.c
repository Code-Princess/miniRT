/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:47:04 by daspring          #+#    #+#             */
/*   Updated: 2024/11/08 11:41:40 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*string_append(char *leading_str, char *trailing_str, \
					size_t len_of_trailing_str)
{
	char	*return_str;
	size_t	pos;
	size_t	leader_len;

	leader_len = string_length(leading_str);
	return_str = malloc((leader_len + len_of_trailing_str + 1) * sizeof(char));
	if (return_str == NULL)
		return (free(leading_str), NULL);
	pos = 0;
	while (leading_str[pos] != STRING_TERMINATOR)
	{
		return_str[pos] = leading_str[pos];
		pos++;
	}
	while (len_of_trailing_str-- > 0)
		return_str[pos++] = *trailing_str++;
	return_str[pos] = STRING_TERMINATOR;
	return (free(leading_str), return_str);
}

size_t	string_length(char string[])
{
	size_t	pos;

	pos = 0;
	while (string[pos] != STRING_TERMINATOR)
		pos++;
	return (pos);
}

// static void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	unsigned char	*to;
// 	unsigned char	*from;
// 	unsigned int	pos;

// 	if (dst == 0 && src == 0)
// 	{
// 		return (dst);
// 	}
// 	to = (unsigned char *)dst;
// 	from = (unsigned char *)src;
// 	pos = 0;
// 	while (n > pos)
// 	{
// 		*(to + pos) = *(from + pos);
// 		pos++;
// 	}
// 	return (dst);
// }

// static void	*ft_memcpy_reverse(void *dst, const void *src, size_t n)
// {
// 	unsigned char	*to;
// 	unsigned char	*from;
// 	size_t			steps;

// 	if (dst == 0 && src == 0)
// 	{
// 		return (dst);
// 	}
// 	to = (unsigned char *)dst;
// 	from = (unsigned char *)src;
// 	steps = 1;
// 	while (!(steps > n))
// 	{
// 		to[n - steps] = from[n - steps];
// 		steps++;
// 	}
// 	return (dst);
// }

// void	*ft_memmove(void *dst, const void *src, size_t n)
// {
// 	if (dst > src)
// 	{
// 		return (ft_memcpy_reverse(dst, src, n));
// 	}
// 	else
// 	{
// 		return (ft_memcpy(dst, src, n));
// 	}
// }
