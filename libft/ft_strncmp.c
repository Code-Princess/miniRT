/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:56:03 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/13 17:06:39 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
