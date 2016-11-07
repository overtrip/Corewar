/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corware.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:13:40 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/07 16:33:42 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include "op.h"

/*
**	Use for define size of errors message in (t_mess)
*/

# define INDEX			20

/*
**	Use to find if fiels exist and their formats
*/

# define FLAG_NAME		1
# define FLAG_COMMENT	2
# define FLAG_LABEL		4

/*
**	Macro for economized lines
*/

# define FLAG_N(flag)	(flag & FLAG_NAME)
# define FLAG_C(flag)	(flag & FLAG_COMMENT)

/*
**	Define a strusture who contain all error massage
*/

typedef struct		s_mess
{
	char			*key_word;
	char			*message;
}					t_mess;

int					print_message(int i);
int					print_message_line(int i, int line);
int					send_id(char *str, int line);
int					error_read(t_head *files);
int					check_content(t_lst *champ, char *file_name);
int					find_prerequis(char *data, unsigned char *flag, int line);
void				open_new_file(t_lst *data, char *file_name);
void				write_name(char *data, int line, int res_open,
		unsigned int *size);
void				write_comment(char *data, int line, int res_open,
		unsigned int *size);

/*
**	Use to debuging in debug.c
*/

void				print_champ_data(t_head *champ);
void				print_content(char **tab);

#endif
