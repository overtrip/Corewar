/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:51:47 by jealonso          #+#    #+#             */
/*   Updated: 2016/09/29 16:00:15 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_push_back(t_head *head, t_lst *elem)
{
	if (elem)
	{
		if (head->tail)
		{
			head->head = elem;
			head->tail = elem;
		}
		else
		{
			head->tail->next = elem;
			elem->prev = head->tail;
			head->tail = elem;
		}
		head->size += 1;
		return (1);
	}
	else
		return (0);
}
