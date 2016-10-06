/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_match.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:30:12 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/05 14:59:59 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_del_match(t_head *head, void *data, int (*cmp)(void *, void *),
		void (*del)(void *))
{
	t_head	*tmp_head;
	t_lst	*tmp;

	tmp_head = head;
	if (!head)
		return ;
	while (tmp_head->head)
	{
		tmp = tmp_head->head;
		if ((*cmp)(tmp_head->head, data))
		{
			tmp->next = tmp_head->head->next;
			tmp_head->head->next->prev = tmp;
			(*del)(tmp_head);
		}
		tmp_head->head = tmp_head->head->next;
	}
}
