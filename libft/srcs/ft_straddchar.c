/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:00:26 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 18:00:35 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_straddchar(char **s, const char c)
{
	int		len;
	char	*tmp;

	len = 2;
	if (*s)
		len = ft_strlen(*s) + 1;
	if ((tmp = ft_strnew(len)) == NULL)
		return ;
	if (*s)
	{
		ft_strcpy(tmp, *s);
		tmp[len - 1] = c;
	}
	else
	{
		tmp[0] = c;
	}
	ft_strdel(s);
	*s = tmp;
}