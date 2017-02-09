/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:31:17 by tettouat          #+#    #+#             */
/*   Updated: 2015/11/24 16:31:29 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenwstr(wchar_t *str)
{
	int		result;

	result = 0;
	while (*str)
		result += ft_lenwchar(*str++);
	return (result);
}
