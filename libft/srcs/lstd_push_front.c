/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:19:05 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:20:41 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_push_front(t_listd **alst, void *new)
{
	t_listd		*front;
	t_listd		*tmp;

	if (!alst || !*alst)
		return (ft_lstd_new(alst, new));
	if ((tmp = (t_listd *)malloc(sizeof(t_listd))) != NULL)
	{
		front = ft_lstd_front(*alst);
		tmp->data = new;
		tmp->prev = NULL;
		tmp->next = front;
		front->prev = tmp;
		*alst = tmp;
	}
}
