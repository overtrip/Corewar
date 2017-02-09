/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:59:26 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 14:58:32 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

void	libx_image_fill(t_libx_img *img, int c)
{
	int		i;
	int		*ptr;

	if (img == NULL)
		return ;
	i = 0;
	ptr = (int *)img->buffer;
	while (i < img->width * img->height)
	{
		*(ptr + i) = c;
		i += 1;
	}
}
