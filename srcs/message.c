/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:26:20 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/06 16:04:30 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Contains all variable message
*/

const t_mess g_usage_tab[INDEX] =
{
	{"empty", ""},
	{"file", "File.s"},
	{"usage", "Usage : corewar file.s"},
	{"open", "Error : can't open file"},
	{"close", "Error : can't close file"},
	{"", "Error"}
};

/*
**	Find a key_word for send to print_messge function
*/

int	send_id(char *str)
{
	int	i;

	i = 0;
	while (i < INDEX)
	{
		if (!ft_strcmp(g_usage_tab[i].key_word, str))
			return (print_message(i));
		++i;
	}
	return (print_message(i));
}

/*
** Check if file_name_terminate by .s
*/

int	compatible_file(char *str)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	i = ft_strlen(str);
	if (i < 3)
		return (print_message(0));
	else
	{
		tmp = i - 2;
		while (tmp < i)
		{
			if (str[tmp] != g_usage_tab[i].key_word[2])
				return (1);
		}
	}
	return (0);
}

/*
**	Print all error according to id message
*/

int	print_message(int i)
{
	ft_putendl_fd(g_usage_tab[i].message, 2);
	return (1);
}
