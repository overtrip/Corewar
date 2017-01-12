/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:51:47 by jealonso          #+#    #+#             */
/*   Updated: 2017/01/09 17:00:04 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_push_back(t_head **head, t_lst *elem)
{
	if (!(*head && elem))
		return (0);
	elem->prev = (*head)->last;
	elem->next = NULL;
	if (!((*head)->first))
		(*head)->first = elem;
	else
		(*head)->last->next = elem;
	(*head)->last = elem;
	(*head)->size++;
	return (1);
}
