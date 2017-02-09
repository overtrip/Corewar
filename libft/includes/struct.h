/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:39:59 by jealonso          #+#    #+#             */
/*   Updated: 2017/02/09 16:14:28 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_read
{
	int				fd;
	char			*content;
	struct s_read	*next;
}					t_read;

typedef struct		s_lists
{
	void			*data;
	struct s_lists	*prev;
	struct s_lists	*next;
}					t_lists;

typedef struct		s_head
{
	size_t			size;
	struct s_lists	*first;
	struct s_lists	*last;
}					t_head;

#endif
