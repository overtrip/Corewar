/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:59:49 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/09 16:05:24 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_del(t_head *head)
{
	t_lists	*save;
	t_lists	*current;

	if (!head)
		return ;
	current = head->first;
	while (current)
	{
		save = current;
		current = current->next;
		free(save->data);
		free(save);
	}
	head->first = NULL;
	head->last = NULL;
}
