/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:08:40 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/26 17:09:18 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strerror(void)
{
	static char		**t = NULL;

	if (t == NULL)
		ini_strerror(&t);
	if (t && errno > 0 && errno <= 106)
		return (t[errno]);
	return (NULL);
}

char	*ft_strerr(int err)
{
	static char		**t = NULL;

	if (t == NULL)
		ini_strerror(&t);
	if (t && err > 0 && err <= 106)
		return (t[err]);
	return (NULL);
}