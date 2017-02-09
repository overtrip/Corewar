/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:18:37 by tettouat          #+#    #+#             */
/*   Updated: 2015/11/24 16:25:54 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_chartostr(const char c)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (0);
	if (c == 0)
		str[0] = '\0';
	else
		str[0] = c;
	str[1] = '\0';
	return (str);
}
