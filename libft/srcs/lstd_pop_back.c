/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_pop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:19:05 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:20:15 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_pop_back(t_listd **alst, void (*del)(void*))
{
	t_listd		*back;

	if (!alst || !*alst)
		return ;
	back = ft_lstd_back(*alst);
	if (*alst == back)
		*alst = back->prev;
	if (back->data && del)
		del(back->data);
	if (back->prev)
		back->prev->next = NULL;
	free(back);
}
