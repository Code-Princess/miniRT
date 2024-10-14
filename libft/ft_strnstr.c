/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 21:46:53 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/14 10:56:20 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_help(const char *str);
static int		ft_strncmp_help(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	haystack_len;

	needle_len = ft_strlen_help(needle);
	haystack_len = ft_strlen_help(haystack);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && needle_len <= len)
	{
		if (ft_strncmp_help(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
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

static int	ft_strncmp_help(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0 && (*cast_s1 != '\0' || *cast_s2 != '\0'))
	{
		if (*cast_s1 != *cast_s2)
		{
			return (*cast_s1 - *cast_s2);
		}
		n--;
		cast_s1++;
		cast_s2++;
	}
	return (0);
}
