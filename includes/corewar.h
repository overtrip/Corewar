/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corware.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:13:40 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/06 16:40:48 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include <stdio.h>
#include <fcntl.h>

# define INDEX 9

/*
**	Define a strusture who contain all error massage
*/

typedef struct		s_mess
{
	char			*key_word;
	char			*message;
}					t_mess;

int	print_message(int i);
int	send_id(char *str);
int	error(t_head *files);

#endif
