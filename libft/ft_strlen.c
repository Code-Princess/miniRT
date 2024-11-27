/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:55:08 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/08 18:25:00 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
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
