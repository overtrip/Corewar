/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_match.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:30:12 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/09 16:05:35 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_del_match(t_head *head, void *data, int (*cmp)(void *, void *),
		void (*del)(void *))
{
	t_head	*tmp_head;
	t_lists	*tmp;

	tmp_head = head;
	if (!head)
		return ;
	while (tmp_head->first)
	{
		tmp = tmp_head->first;
		if ((*cmp)(tmp_head->first, data))
		{
			tmp->next = tmp_head->first->next;
			tmp_head->first->next->prev = tmp;
			(*del)(tmp_head);
		}
		tmp_head->first = tmp_head->first->next;
	}
}
