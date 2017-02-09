/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:01:08 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/09 16:06:24 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_push_front(t_head *head, t_lists *elem)
{
	if (elem)
	{
		if (!head->first)
		{
			head->first = elem;
			head->last = elem;
		}
		else
		{
			head->first->prev = elem;
			elem->next = head->first;
			head->first = elem;
		}
		head->size += 1;
		return (1);
	}
	return (0);
}
