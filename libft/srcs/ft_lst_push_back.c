/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 13:51:47 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/09 16:06:10 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_push_back(t_head **head, t_lists *elem)
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
