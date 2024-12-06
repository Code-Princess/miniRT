/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:56:03 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/06 13:26:32 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	while ((*cast_s1 != '\0' || *cast_s2 != '\0'))
	{
		if (*cast_s1 != *cast_s2)
		{
			return (*cast_s1 - *cast_s2);
		}
		cast_s1++;
		cast_s2++;
	}
	return (0);
}
