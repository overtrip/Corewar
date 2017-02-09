/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_match.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:28:59 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/09 16:14:58 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lists	*ft_lst_match(t_head *head, void *data, int (*cmp)(void *, void *))
{
	t_head	*tmp;
	t_head	*new_head;

	tmp = head;
	new_head = head;
	while (tmp)
	{
		if ((*cmp)(tmp->first->data, data))
			ft_lst_push_back(&new_head, ft_lst_create_no_malloc(data));
		tmp->first = tmp->first->next;
	}
	return (new_head->first);
}
