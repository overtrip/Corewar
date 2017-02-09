/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keepstring_inv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:22:34 by tettouat          #+#    #+#             */
/*   Updated: 2016/01/05 16:22:33 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_keepstring_inv(const char c, char *str)
{
	str = ft_strjoin(ft_chartostr(c), str);
	return (str);
}
