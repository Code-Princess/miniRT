/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:50:57 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/18 15:56:41 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*resultstr;
	size_t			strlen;

	index = 0;
	strlen = ft_strlen(s);
	resultstr = malloc(strlen + 1);
	if (resultstr == NULL)
		return (NULL);
	while (index < strlen)
	{
		resultstr[index] = (*f)(index, s[index]);
		index++;
	}
	resultstr[index] = '\0';
	return (resultstr);
}

/* char wrapperToUpper(unsigned int index, char c)
{
	return (index, ft_toupper(c));
}

int main() {
    // Beispiel-Eingabezeichenkette
    const char *input = "hello world";

    // Verwende ft_strmapi, um die Zeichenkette mit toupper zu verarbeiten
    char *result = ft_strmapi(input, &wrapperToUpper);

    if (result != NULL) {
        printf("Original: %s\n", input);
        printf("Nach toupper: %s\n", result);
        free(result); // Speicher freigeben, sobald er nicht mehr benötigt wird
    } else {
        printf("Speicherzuweisung fehlgeschlagen.\n");
    }

    return 0;
} */