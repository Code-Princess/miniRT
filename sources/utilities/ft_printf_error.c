/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:42:59 by daspring          #+#    #+#             */
/*   Updated: 2024/12/05 15:38:08 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "../../libft/libft.h"

static int	process_specifier(char specifier, va_list *arg_list, int *counter);
static int	ft_putchar_error(char c);
static int	ft_putstr_error(char *s);

int	ft_printf_error(const char *format, ...)
{
	va_list	arg_list;
	int		counter;

	counter = 0;
	va_start(arg_list, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (process_specifier(*(++format), &arg_list, &counter) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar_error(*format) == -1)
				return (-1);
			counter++;
		}
		format++;
	}
	if (*format == '\0')
		return (counter);
	return (-1);
}

static int	process_specifier(char specifier, va_list *arg_list, int *counter)
{
	int	ret_value;

	if (specifier == '%')
		ret_value = ft_putchar_error('%');
	else if (specifier == 'c')
		ret_value = ft_putchar_error(va_arg(*arg_list, int));
	else if (specifier == 's')
		ret_value = ft_putstr_error(va_arg(*arg_list, char *));
	else
		return (0);
	if (ret_value == -1)
		return (-1);
	*counter += ret_value;
	return (0);
}

static int	ft_putchar_error(char c)
{
	return (write(2, &c, 1));
}

static int	ft_putstr_error(char *s)
{
	int	len;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (write(2, s, len) == -1)
		return (-1);
	return (len);
}
