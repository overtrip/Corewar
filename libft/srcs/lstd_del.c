/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:19:05 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:19:41 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_del(t_listd **alst, void (*del)())
{
	t_listd		*next;
	t_listd		*prev;

	if (!alst || !*alst)
		return ;
	if ((*alst)->prev == NULL)
		return (ft_lstd_pop_front(alst, del));
	next = (*alst)->next;
	prev = (*alst)->prev;
	if ((*alst)->data && del)
		del((*alst)->data);
	if (next)
		next->prev = prev;
	if (prev)
		prev->next = next;
	free(*alst);
	*alst = next;
}
