/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:34:37 by tettouat          #+#    #+#             */
/*   Updated: 2015/11/25 14:38:22 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(long long n)
{
	char				*dst;
	unsigned long long	tmp;
	int					len;

	tmp = n > 0 ? n : -n;
	len = 1;
	while ((tmp /= 10) != 0)
		len++;
	tmp = n > 0 ? n : -n;
	if (n < 0)
		len++;
	if (!(dst = ft_strnew(len)))
		return (0);
	while (len--)
	{
		dst[len] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (n < 0)
		dst[0] = '-';
	return (dst);
}
