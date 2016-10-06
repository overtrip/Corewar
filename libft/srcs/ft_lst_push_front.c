/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:01:08 by jealonso          #+#    #+#             */
/*   Updated: 2016/09/29 16:05:22 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_push_front(t_head *head, t_lst *elem)
{
	if (elem)
	{
		if (!head->head)
		{
			head->head = elem;
			head->tail = elem;
		}
		else
		{
			head->head->prev = elem;
			elem->next = head->head;
			head->head = elem;
		}
		head->size += 1;
		return (1);
	}
	return (0);
}
