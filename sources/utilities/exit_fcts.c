/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fcts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:04:48 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/22 13:26:37 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../includes/utilities.h"

void	print_error_and_exit(char *message, char *identifier)
{
	ft_printf_error("Error\n");
	ft_printf_error("%s: %s\n", identifier, message);
	exit(1);
}
