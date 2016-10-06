/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_init_head.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:35:08 by jealonso          #+#    #+#             */
/*   Updated: 2016/09/29 15:59:41 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_head	*ft_lst_init_head(t_head *head, t_lst *elem)
{
	if ((head = (t_head *)malloc(sizeof(t_head))))
		return (NULL);
	else
	{
		if (elem)
			head->size = 1;
		else
			head->size = 0;
		head->head = elem;
		head->tail = elem;
	}
	return (head);
}
