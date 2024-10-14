/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:19:07 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/15 13:32:56 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_nr(char const *s, char c);
static char	*cpyaword(char const *s, int start, int end);
static void	*free_memory(char **strings, int count);
static void	init_vars(size_t *i, int *result_index, int *word_start_index);

char	**ft_split(char const *s, char c)
{
	char	**resultarray;
	size_t	i;
	int		result_index;
	int		word_start_index;

	init_vars(&i, &result_index, &word_start_index);
	resultarray = ft_calloc((word_nr(s, c) + 1), sizeof(char *));
	if (resultarray == NULL)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && word_start_index < 0)
			word_start_index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && word_start_index >= 0)
		{
			resultarray[result_index] = cpyaword(s, word_start_index, i);
			if (resultarray[result_index] == NULL)
				return (free_memory(resultarray, result_index));
			word_start_index = -1;
			result_index++;
		}
		i++;
	}
	return (resultarray);
}

static void	init_vars(size_t *i, int *result_index, int *word_start_index)
{
	*i = 0;
	*result_index = 0;
	*word_start_index = -1;
}

static int	word_nr(char const *s, char c)
{
	int	nr;
	int	isseparator;

	nr = 0;
	isseparator = 0;
	while (*s != '\0')
	{
		if (*s != c && isseparator == 0)
		{
			isseparator = 1;
			nr++;
		}
		else if (*s == c)
			isseparator = 0;
		s++;
	}
	return (nr);
}

static char	*cpyaword(char const *s, int start, int end)
{
	char	*dest_word;
	int		i;

	i = 0;
	dest_word = malloc(end - start + 1);
	if (dest_word == NULL)
		return (NULL);
	while (start < end)
	{
		dest_word[i] = s[start];
		start++;
		i++;
	}
	dest_word[i] = '\0';
	return (dest_word);
}

static void	*free_memory(char **strings, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (NULL);
}

/* int	main(void)
{
	// test function word_nr(char const *s, char c)
	char	s1[4] = "a--b";
	char	s2[12] = "abcde-kl-578";

	printf("The wordnr of the string %s is: %d\n", s1, word_nr(s1, '-'));
	printf("The wordnr of the string %s is: %d\n\n", s2, word_nr(s2, '-'));

	// test function cpyaword(char const *s, int start, int end)
	char	s3[12] = "abcde_kl_578";
	int start = 2;
	int end = 4;
	char *word = cpyaword(s3, start, end);
	printf("the result of cpyaword(%s, %d. %d) is: %s", s3, start, end, word);
	return (0);
} */
