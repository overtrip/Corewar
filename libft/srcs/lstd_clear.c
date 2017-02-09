/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:19:05 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:19:33 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_clear(t_listd **alst, void (*del)(void*))
{
	t_listd		*tmp;

	if (!alst || !*alst)
		return ;
	while (*alst)
	{
		if (del)
			del((*alst)->data);
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp);
	}
}
