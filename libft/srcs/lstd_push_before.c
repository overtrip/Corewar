/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_push_before.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:19:05 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:20:33 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_push_before(t_listd **alst, void *new)
{
	t_listd		*tmp;

	if (!alst || !*alst)
	{
		ft_lstd_new(alst, new);
		return ;
	}
	if ((tmp = (t_listd *)malloc(sizeof(t_listd))) != NULL)
	{
		tmp->data = new;
		tmp->prev = (*alst)->prev;
		tmp->next = *alst;
		if ((*alst)->prev)
		{
			(*alst)->prev->next = tmp;
			(*alst)->prev = tmp;
		}
		*alst = tmp;
	}
}
