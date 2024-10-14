/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:56:38 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/14 10:33:16 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			cast_c;
	const char		*cast_s;
	size_t			i;

	cast_c = (char)c;
	cast_s = s;
	i = 0;
	while (i < n)
	{
		if (cast_s[i] == cast_c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
