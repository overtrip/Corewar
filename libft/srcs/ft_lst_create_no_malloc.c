/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_create_no_malloc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:28:49 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/09 16:11:27 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lists	*ft_lst_create_no_malloc(void *data)
{
	t_lists	*new;

	if (!(new = (t_lists *)malloc(sizeof(t_lists))))
		return (NULL);
	else
	{
		new->data = data;
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}
