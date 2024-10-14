/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:14:25 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/14 16:35:29 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_help(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinedstr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen_help(s1);
	s2_len = ft_strlen_help(s2);
	joinedstr = (char *)malloc(s1_len + s2_len + 1);
	if (joinedstr == 0)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		joinedstr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		joinedstr[i] = *s2;
		s2++;
		i++;
	}
	joinedstr[i] = '\0';
	return (joinedstr);
}

static size_t	ft_strlen_help(const char *s)
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
