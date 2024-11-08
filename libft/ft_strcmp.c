/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:56:03 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/08 12:53:18 by daspring         ###   ########.fr       */
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