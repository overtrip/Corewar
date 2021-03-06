/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aisi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:03:01 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:04:23 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_aisi(const char *s)
{
	if (s == NULL || *s == '\0')
		return (false);
	if (*s == '-' && (*s + 1) != '\0')
		++s;
	while (*s != '\0' && *s >= '0' && *s <= '9')
		++s;
	if (*s == '\0')
		return (true);
	return (false);
}
