/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:55:08 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/14 09:12:39 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
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

/* int	main(void)
{
	const char	*s = "hy3";

	printf("my ft_strlen of the string %s is %lu\n", s, ft_strlen(s));
	printf("lib strlen of the string %s is %lu\n", s, strlen(s));
	return (0);
} */
