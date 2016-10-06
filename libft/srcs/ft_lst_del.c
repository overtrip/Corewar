/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:59:49 by jealonso          #+#    #+#             */
/*   Updated: 2016/09/30 17:27:58 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_del(t_head *head)
{
	t_lst	*save;

	while (head->head != head->tail)
	{
		save = head->head;
		head->head = head->head->next;
		free(save);
	}
	free(head->tail);
	free(head);
}
