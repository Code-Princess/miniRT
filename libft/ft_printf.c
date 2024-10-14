/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:51:51 by llacsivy          #+#    #+#             */
/*   Updated: 2024/04/09 15:14:14 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkplaceholder(char c, va_list args, int *error_ptr);

int	ft_printf(const char *inputStr, ...)
{
	va_list	args;
	int		str_len;
	int		error;

	error = 0;
	str_len = 0;
	va_start(args, inputStr);
	while (*inputStr != '\0')
	{
		if (*inputStr != '%')
		{
			str_len += ft_putchar(*inputStr, &error);
			if (error == -1)
				return (error);
		}
		else if (*inputStr == '%')
		{
			str_len += ft_checkplaceholder(*(++inputStr), args, &error);
			if (error == -1)
				return (error);
		}
		inputStr++;
	}
	va_end(args);
	return (str_len);
}

static int	ft_checkplaceholder(char c, va_list args, int *error_ptr)
{
	int		char_len;

	char_len = 0;
	if (c == 'c')
		char_len = ft_putchar(va_arg(args, int), error_ptr);
	else if (c == 's')
		char_len = ft_putstr(va_arg(args, char *), error_ptr);
	else if (c == 'p')
		char_len = ft_putptr(va_arg(args, long long), error_ptr);
	else if (c == 'd' || c == 'i')
		char_len = ft_putnbr(va_arg(args, int), error_ptr);
	else if (c == 'u')
		char_len = ft_putnbr_unsigned(va_arg(args, unsigned int), error_ptr);
	else if (c == 'x')
		char_len = ft_puthexadecnbr(va_arg(args, int), error_ptr);
	else if (c == 'X')
		char_len = ft_puthexadecnbr_upper(va_arg(args, int), error_ptr);
	else if (c == '%')
		char_len = ft_putpercent(error_ptr);
	if (*error_ptr == -1)
		return (*error_ptr);
	else
		return (char_len);
}

/* int	main(void)
{
	// printf("%c: lib printf\n", '0');
	// ft_printf("%c: my ft_printf\n\n", '0');
	// printf("%s", "lib printf:\n");
	// printf("%d: is the char_len\n", printf("%s", (char *) NULL));
	// printf("%s", "my ft_printf:\n");
	// printf("%d: is the char_len\n\n", ft_printf("%s", (char *) NULL));
	// printf("%s", "lib printf:\n");
	// printf("%d: is the char_len\n", printf(" %p %p \n", 0, 0));
	// printf("%s", "my ft_printf:\n");
	// printf("%d: is the char_len\n\n", ft_printf(" %p %p \n", 0, 0));
	// printf("%s", "lib printf:\n");
	// printf("%p \n", LONG_MIN);
	// printf("%s", "my ft_printf:\n");
	// ft_printf("%p \n\n", (void *)LONG_MIN);
	// printf("%s", "lib printf:\n");
	// printf("%p \n", LONG_MAX);
	// printf("%s", "my ft_printf:\n");
	// ft_printf("%p \n\n", LONG_MAX);
	// printf("%s", "lib printf:\n");
	// printf(" %p \n", 17);
	// printf("%s", "my ft_printf:\n");
	// ft_printf(" %p \n\n", 17);
	// printf("%s", "lib printf:\n");
	// printf(" %u \n", 0);
	// printf("%s", "my ft_printf:\n");
	// ft_printf(" %u \n\n", 0);
	// printf("%s", "lib printf:\n");
	// printf("%p \n", -1);
	// printf("%s", "my ft_printf:\n");
	// ft_printf("%p \n\n", -1);
	// printf("%s", "lib printf for %x:\n");
	// printf("%x \n", -1);
	// printf("%s", "my ft_printf for %x:\n");
	// ft_printf("%%c \n\n", -1);
	// printf("%s", "lib printf for %%c:\n");
	// printf("%%c\n");
	// printf("%s", "my ft_printf for %%c:\n");
	// ft_printf("%%c\n\n");
	// printf("%s", "lib printf\n");
	// printf("%p\n", "");
	// printf("%s", "my ft_printf\n");
	// ft_printf("%p\n", "");
	// printf("%s", "lib printf\n");
	// printf("0x%p-\n", (void *)ULONG_MAX);
	// printf("%s", "my ft_printf\n");
	// ft_printf("0x%p-\n", (void *)ULONG_MAX);
	printf("%s", "lib printf\n");
	printf("%d\n", -10);
	printf("%s", "my ft_printf\n");
	ft_printf("%d\n", -10);
	return (0);
} */
