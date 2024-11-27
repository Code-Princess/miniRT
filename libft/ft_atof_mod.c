/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:25:33 by daspring          #+#    #+#             */
/*   Updated: 2024/11/27 13:51:01 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
// #include "../include/fractol.h"

static int		find_signum(char *s, int *signum);
static double	get_number_part_greater_one(char *s, int *pos, double number);
static double	get_number_part_smaller_one(char *s, int *pos, double number);
static int		is_whitespace(char c);

double	ft_atof_mod(char *s, int *error)
{
	double	number;
	int		signum;
	int		pos;

	number = 0.0;
	signum = 1;
	pos = find_signum(s, &signum);
	if (!ft_isdigit(s[pos]))
		error = 1;
	number = get_number_part_greater_one(s, &pos, number);
	if (number < 0)
		error = 1;
	if (s[pos] == '.')
		pos++;
	number = get_number_part_smaller_one(s, &pos, number);
	while (is_whitespace(s[pos]))
		pos++;
	if (s[pos] != '\0')
printf("bad input via atof\n");
		// bad_input_termination();
	return (number * signum);
}

static int	find_signum(char *s, int *signum)
{
	int	pos;

	pos = 0;
	if (s[pos] == '-')
	{
		*signum = -1;
		pos++;
	}
	else if (s[pos] == '+')
		pos++;
	return (pos);
}

static double	get_number_part_greater_one(char *s, int *pos, double number)
{
	while (s[*pos] && ft_isdigit(s[*pos]))
	{
		number = number * 10.0 + (s[*pos] - '0');
		(*pos)++;
	}
	if (*pos > 4)
		return (-1.0);
	return (number);
}

static double	get_number_part_smaller_one(char *s, int *pos, double number)
{
	double	decimal_place;

	decimal_place = 0.1;
	while (s[*pos] && ft_isdigit(s[*pos]))
	{
		number = number + (decimal_place * (s[*pos] - '0'));
		decimal_place *= 0.1;
		(*pos)++;
	}
	return (number);
}

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}
