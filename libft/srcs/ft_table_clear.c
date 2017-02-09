/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:54:14 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:54:27 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_table_clear(void ***atbl, void (*del)())
{
	size_t	i;

	if (atbl == NULL)
		return ;
	i = ft_table_size(*atbl);
	while (i > 0)
	{
		del((*atbl)[i - 1]);
		--i;
	}
	free(*atbl);
	*atbl = NULL;
}