/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:31:12 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/18 17:55:05 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Initialise tab with size 10
*/

int	init_content(char **tab)
{
	int	i;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *))))
		return (send_id("no_malloc_struct"));
	while (i < 10)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char))))
			return (send_id("no_malloc_data"));
		tab[i] = NULL;
		++i;
	}
	return (0);
}


/*
**	Cut the string to the first occurence
*/

char	*cut_str(char *str, char c)
{
	char	*str_cutting;
	char	*tmp;

	tmp = str;
	str_cutting = NULL;
	if (!str)
		return (NULL);
	while (tmp && *tmp != c)
		++tmp;
	if (!tmp)
		return (NULL);
	else
		str_cutting = tmp;
	ft_putendl(str_cutting);
	return (str_cutting);
}

/*
**	Check if name and comment field exist and there size
*/

int	fondamental(char *str)
{
	char	*buff;
	size_t	size;

	size = 0;
	if (!(buff = cut_str(str, '"')))
		return (1);
	ft_putendl(buff);
/*	if (ft_strcmp(buff, ".name"))
	{
		if (size > PROG_NAME_LENGTH)
			return (send_id("size_name"));
	}
	if (ft_strcmp(buff, ".comment"))
	{
		if (size > COMMENT_LENGTH)
			return (send_id("size_comment"));
	}
	printf("%zu \n", size);*/
//	free(&buff);
	return (0);
}

/*
**	Check if label was called and if they are a good structure
*/

int	exist(char *data, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (i > 1 && ft_strstr(tab[i], data))
			ft_putendl("lol");
		else
			tab[i] = ft_strdup(data);
		++i;
	}
	return (0);
}

/*
**	Check if champ has good parameters
*/

int	check_content(t_head *champ)
{
	t_lst		*line_champ;
	char		**tab;

	line_champ = champ->first;
	tab = NULL;
	if (init_content(tab))
		return (1);
	while (line_champ)
	{
		if (fondamental(line_champ->data))
			return (send_id("error_size"));
//		if (ft_strstr(line_champ->data, ".name"))
//			ft_putendl(line_champ->data);
//		if (exist(line_champ->data, tab))
//			return (0);
		line_champ = line_champ->next;
	}
	return (0);
}
