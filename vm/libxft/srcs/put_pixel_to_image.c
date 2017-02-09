/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:59:26 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 14:58:56 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

void	libx_put_pixel_to_image(t_libx_img *img, int x, int y, int c)
{
	char	*ptr_color;

	if (img == NULL || x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	ptr_color = img->buffer + (x * (img->bits_per_pixel >> 3)
			+ y * img->size_line);
	ptr_color[0] = (c >> 0x00) & 0xFF;
	ptr_color[1] = (c >> 0x08) & 0xFF;
	ptr_color[2] = (c >> 0x10) & 0xFF;
}
