/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstd_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:19:05 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:20:02 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstd_new(t_listd **alst, void *new)
{
	t_listd		*tmp;

	if ((tmp = (t_listd *)malloc(sizeof(t_listd))) != NULL)
	{
		tmp->data = new;
		tmp->prev = NULL;
		tmp->next = NULL;
		*alst = tmp;
	}
}
