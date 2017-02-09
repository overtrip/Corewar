/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_pop_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:19:05 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:20:20 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_pop_front(t_listd **alst, void (*del)())
{
	t_listd		*front;

	if (!alst || !*alst)
		return ;
	front = ft_lstd_front(*alst);
	if (*alst == front)
		*alst = front->next;
	if (front->data && del)
		del(front->data);
	if (front->next)
		front->next->prev = NULL;
	free(front);
}
