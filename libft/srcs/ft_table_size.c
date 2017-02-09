/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:55:47 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:55:58 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_table_size(void **tbl)
{
	size_t	i;

	if (tbl == NULL)
		return (0);
	i = 0;
	while (tbl[i])
		++i;
	return (i);
}