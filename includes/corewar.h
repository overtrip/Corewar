/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corware.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:13:40 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/18 17:20:45 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include <stdio.h>
#include <fcntl.h>
#include "op.h"

# define INDEX 11

/*
**	Define a strusture who contain all error massage
*/

typedef struct		s_mess
{
	char			*key_word;
	char			*message;
}					t_mess;

int		print_message(int i);
int		send_id(char *str);
int		error_read(t_head *files);
int		check_content(t_head *champ);

/*
**	Use to debuging in debug.c
*/

void	print_champ_data(t_head *champ);
void	print_content(char **tab);

#endif
