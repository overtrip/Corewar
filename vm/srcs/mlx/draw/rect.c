/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:59:26 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 16:20:59 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vm_mlx_draw_rect(t_libx_img *img, int xy[2], int wh[2],
		int color)
{
	int		i;
	int		j;

	i = xy[0];
	j = xy[1];
	while (i < xy[0] + wh[0])
		libx_put_pixel_to_image(img, i++, j, color);
	--i;
	while (j < xy[1] + wh[1])
		libx_put_pixel_to_image(img, i, j++, color);
	--j;
	while (i > xy[0])
		libx_put_pixel_to_image(img, --i, j, color);
	while (j > xy[1])
		libx_put_pixel_to_image(img, i, --j, color);
}
