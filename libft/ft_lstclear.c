/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:35:58 by llacsivy          #+#    #+#             */
/*   Updated: 2024/03/19 15:49:49 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_node;
	t_list	*tmp_node;

	current_node = *lst;
	while (current_node != NULL)
	{
		tmp_node = current_node;
		current_node = current_node->next;
		del(tmp_node->content);
		free(tmp_node);
	}
	*lst = NULL;
}
