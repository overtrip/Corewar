/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_match.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:28:59 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/05 15:08:46 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lst_match(t_head *head, void *data, int (*cmp)(void *, void *))
{
	t_head	*tmp;
	t_head	*new_head;

	tmp = head;
	new_head = head;
	while (tmp)
	{
		if ((*cmp)(tmp->head->data, data))
			ft_lst_push_back(new_head, ft_create_no_malloc(data));
		tmp->head = tmp->head->next;
	}
	return (new_head->head);
}
