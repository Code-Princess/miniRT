/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:44:45 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/14 14:16:54 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_help(const char *s);

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)malloc(ft_strlen_help(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		s2[i] = *s1;
		s1++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlen_help(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}
