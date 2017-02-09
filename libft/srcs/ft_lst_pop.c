/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:11:36 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/09 16:06:04 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lists	*ft_lst_pop(t_head *head, size_t pos)
{
	t_lists	*current;
	size_t	i;

	current = head->first;
	i = 0;
	if (!head)
		return (NULL);
	while (i < pos)
		current = current->next;
	if (current)
	{
		current->prev = current->next;
		current->next->prev = current->prev;
		current->next = NULL;
		current->prev = NULL;
	}
	return (current);
}
