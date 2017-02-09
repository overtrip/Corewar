/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_push_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:19:05 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:20:24 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_push_after(t_listd **alst, void *new)
{
	t_listd		*after;
	t_listd		*tmp;

	if (!alst || !*alst)
	{
		ft_lstd_new(alst, new);
		return ;
	}
	if ((tmp = (t_listd *)malloc(sizeof(t_listd))) != NULL)
	{
		after = (*alst)->next;
		tmp->data = new;
		tmp->prev = *alst;
		tmp->next = after;
		(*alst)->next = tmp;
	}
}
