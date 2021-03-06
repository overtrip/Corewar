/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:13:40 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/10 17:51:23 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <fcntl.h>

/*
**	TODO To delete after tests because used to printf function
*/

# include <stdio.h>

/*
**	Use for define size of errors message in (t_mess)
*/

# define INDEX			20

/*
**	Use to define who much function op_t contain
*/

# define SIZE			17

/*
**	Use to find if fiels exist and their formats
*/

# define FLAG_NAME		1
# define FLAG_COMMENT	2
# define FLAG_LABEL		4
# define FLAG_INST		8
# define FLAG_AFTER		16

/*
**	Macro for economized lines
*/

# define FLAG_N(flag)	(flag & FLAG_NAME)
# define FLAG_C(flag)	(flag & FLAG_COMMENT)
# define DATA ((t_instruct *)(save)->data)

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
	int					op_code;
	int					*arg_type;
	char				**arg_value;
	struct s_instruct	*next;
}						t_instruct;

/*
**	Struct to economized lines in check_content.c
*/

typedef struct			s_posandflag
{
	int					line;
	unsigned int		pos;
	unsigned char		flag;
}						t_posandflag;

int						print_message(int i);
int						print_message_line(int i, int line);
int						send_id(char *str, int line);
int						error_read(t_head *files);
int						check_content(t_lists *champ, char *file_name);
int						find_prerequis(char *data, unsigned char *flag,
		int line);
void					open_new_file(char *file_name, t_head *head,
		t_head *label_pos, t_lists *champ);
void					write_name(char *data, t_header *head,
		unsigned int *size);
void					write_comment(char *data, t_header *head,
		unsigned int *size);
void					write_instruction(t_head *ordre, t_head *label);
void					find_pos_label(char	**data, unsigned int *size,
		t_head *pos);
char					*parse_strsep(char **str, const char *delim);
void					print_header(t_header head, int res_open);
void					create_instruction(t_head *head, int index, char **str,
															t_posandflag *var);
int						find_label(unsigned char *flag, int line);
int						find_flag_inst(unsigned char *flag);
char					define_type(char *str);
int						find_instruction(char **data, t_posandflag *var,
																t_head *head);
void					delete_instruction(t_head *head);
int						is_t_lab(char *str);

/*
**	Use to debuging in debug.c
*/

void					print_champ_data(t_head *champ);
void					print_content(char **tab);
void					print_label(t_head *label);
void					print_instruction(t_head *instruction);

#endif
