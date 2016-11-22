/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corware.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:13:40 by jealonso          #+#    #+#             */
/*   Updated: 2016/11/22 13:56:58 by jealonso         ###   ########.fr       */
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

typedef struct			s_mess
{
	char				*key_word;
	char				*message;
}						t_mess;

typedef struct			s_order
{
	unsigned int		pos;
	char				*label;
	struct s_order		*next;
}						t_order;

typedef struct			s_instruct
{
	char				op_code;
	int					arg_type[3];
	int					arg_value[3];
	struct s_instruct	*next;
}						t_instruct;

int						print_message(int i);
int						print_message_line(int i, int line);
int						send_id(char *str, int line);
int						error_read(t_head *files);
int						check_content(t_lst *champ, char *file_name);
int						find_prerequis(char *data, unsigned char *flag,
		int line);
void					open_new_file(t_lst *data, char *file_name);
void					write_name(char *data, t_header *head,
		unsigned int *size);
void					write_comment(char *data, t_header *head,
		unsigned int *size);
void					find_pos_label(char **data, unsigned int *size,
		t_order **pos);
char					*ft_strsep(char **str, const char *delim);
void					print_header(t_header head, int res_open);

/*
**	Use to debuging in debug.c
*/

void					print_champ_data(t_head *champ);
void					print_content(char **tab);

#endif
