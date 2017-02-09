/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_file_to_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:59:26 by tettouat          #+#    #+#             */
/*   Updated: 2017/01/30 14:59:06 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libxft.h"

#include <mlx.h>
#include <stdlib.h>

t_libx_img	*libx_xpm_file_to_image(void *mlx, char *path_file)
{
	t_libx_img	*img;

	if ((img = (t_libx_img *)malloc(sizeof(t_libx_img))) == NULL)
		return (NULL);
	img->img_ptr = mlx_xpm_file_to_image(mlx, path_file,
			&(img->width), &(img->height));
	if (img->img_ptr == NULL)
	{
		free(img);
		return (NULL);
	}
	img->buffer = mlx_get_data_addr(img->img_ptr,
			&(img->bits_per_pixel), &(img->size_line), &(img->endian));
	return (img);
}
