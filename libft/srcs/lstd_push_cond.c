/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_push_cond.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:19:05 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:20:37 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_push_cond(t_listd **alst, void *new,
		int (*cond)())
{
	t_listd		*tmp_next;
	t_listd		*tmp;

	if (!alst || !*alst)
		return (ft_lstd_new(alst, new));
	tmp_next = ft_lstd_front(*alst);
	while (tmp_next && !cond(tmp_next->data, new))
		tmp_next = tmp_next->next;
	if (!tmp_next)
		return (ft_lstd_push_back(alst, new));
	if ((tmp = (t_listd *)malloc(sizeof(t_listd))) == NULL)
		return ;
	tmp->data = new;
	tmp->prev = tmp_next->prev;
	if (tmp_next->prev)
		tmp_next->prev->next = tmp;
	else
		*alst = tmp;
	tmp->next = tmp_next;
	tmp_next->prev = tmp;
}
