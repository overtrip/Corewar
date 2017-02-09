/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:34:38 by tettouat          #+#    #+#             */
/*   Updated: 2015/11/24 16:34:47 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr(wchar_t *str)
{
	int		result;

	result = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
		result += ft_putwchar(*str++);
	return (result);
}
