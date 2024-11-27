/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:24:50 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/22 14:06:10 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "./objects.h"

void	free_char_ptr_array(char **ptr_array);
void	free_obj_ptr_array(t_object **ptr_array);

#endif
