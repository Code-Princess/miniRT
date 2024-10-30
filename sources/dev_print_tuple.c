/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_print_tuple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:21:10 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/30 13:21:11 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../includes/maths.h"

void	print_tuple(t_tuple tuple)
{
	printf("tuple (%f, %f, %f, %d)\n", tuple.x, tuple.y, tuple.z, tuple.w);
}
