/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:27:47 by daspring          #+#    #+#             */
/*   Updated: 2024/12/06 13:42:22 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

int		ft_printf_error(const char *format, ...);
void	error_and_exit(char *message, char *identifier);
void	error_and_exit2(char *message, char *identifier, t_object *obj);

#endif
