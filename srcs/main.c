/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:22:15 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/06 16:54:42 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	TODO Call to parse instructions
*/

/*
**	Initialise all to 0 or NULL
*/

static void	init_null(t_head **files)
{
	*files = NULL;
}

/*
**	Calling to  open and close files
*/

int	open_files(char *file_name, t_head *files)
{
	int	res_open;

	if ((res_open = open(file_name, O_RDONLY)) < 0)
		return (send_id("open"));
	else
	{
		if (error_read(files))
			printf("TODO cas erreur\n");
		else
			printf("TODO cas normal\n");
	}
	if (close(res_open) < 0)
		return (send_id("close"));
	return (0);
}

/*
**	You know that
*/

int	main(int argc, char **argv)
{
	int	i;
	t_head	*files;

	i = 0;
	init_null(&files);
	if (argc < 2 || argc > 5)
		return (send_id("usage"));
	while (++i < argc)
		if (open_files(argv[i], files))
			return (1);
	return (0);
}
