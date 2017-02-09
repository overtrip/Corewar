/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:59:26 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 14:58:51 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

#include <mlx.h>
#include <stdlib.h>

t_libx_img	*libx_new_image(void *mlx, int width, int height)
{
	t_libx_img	*img;

	if ((img = (t_libx_img *)malloc(sizeof(t_libx_img))) == NULL)
		return (NULL);
	img->width = width;
	img->height = height;
	img->img_ptr = mlx_new_image(mlx, width, height);
	if (img->img_ptr == NULL)
	{
		free(img);
		return (NULL);
	}
	img->buffer = mlx_get_data_addr(img->img_ptr,
			&(img->bits_per_pixel), &(img->size_line), &(img->endian));
	return (img);
}
