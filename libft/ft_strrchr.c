/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:28:48 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/14 18:51:55 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cast_c;
	int		j;

	cast_c = (char)c;
	j = ft_strlen(s);
	while (s[j] != cast_c && j > 0)
		j--;
	if (s[j] == cast_c)
		return ((char *)s + j);
	return (NULL);
}
