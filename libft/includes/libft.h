/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 11:46:26 by tettouat          #+#    #+#             */
/*   Updated: 2017/02/09 16:24:01 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 1024
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <wchar.h>
# include <errno.h>
# include "struct.h"

typedef struct s_circular_list	t_lst;

struct			s_circular_list
{
	t_lst		*next;
	t_lst		*start;
	char		*str;
};

typedef enum		e_bool
{
	false,
	true
}					t_bool;

/*
** PART 1
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strncpy(char *s1, const char *s2, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** PART 2
*/
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char	(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
size_t			ft_putchar(const char c);
size_t			ft_putstr(char const *s);
size_t			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** GET_NEXT_LINE
*/
int				get_next_line(int const fd, char **line);

/*
** PRINTF
*/
int					ft_printf(const char *format, ...);
int					ft_sprintf(char *str, const char *format, ...);
int					ft_asprintf(char **ret, const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);

/*
** LIST
*/
typedef struct		s_listd
{
	void			*data;
	struct s_listd	*prev;
	struct s_listd	*next;
}					t_listd;

size_t				ft_lstd_size(t_listd *lstd);
t_listd				*ft_lstd_front(t_listd *lstd);
t_listd				*ft_lstd_back(t_listd *lstd);
void				ft_lstd_new(t_listd **alst, void *new);
void				ft_lstd_push_front(t_listd **alst, void *new);
void				ft_lstd_push_back(t_listd **alst, void *new);
void				ft_lstd_pop_front(t_listd **alst, void (*del)());
void				ft_lstd_pop_back(t_listd **alst, void (*del)());
void				ft_lstd_push_after(t_listd **alst, void *new);
void				ft_lstd_push_before(t_listd **alst, void *new);
void				ft_lstd_push_cond(t_listd **alst, void *new,
		int (*cond)());
void				ft_lstd_del(t_listd **alst, void (*del)());
void				ft_lstd_clear(t_listd **alst, void (*del)());
void				ft_lstd_map(t_listd **alst, void (*map)());
void				ft_lstd_rmap(t_listd **alst, void (*map)());
void				ft_lstd_do(t_listd **alst, int (*cmp)(),
		void (*action)(), int type);

t_head				*ft_lst_init_head(t_head *head, t_lists *elem);
t_lists				*ft_lst_create_no_malloc(void *data);
t_lists				*ft_lst_match(t_head *head, void *data, int (*cmp)(void *,
		void *));
t_lists				*ft_lst_pop(t_head *head, size_t pos);
int					ft_lst_foreach(t_head *head, int (*func)(void *));
int					ft_lst_push_front(t_head *head, t_lists *elem);
int					ft_lst_push_back(t_head **head, t_lists *elem);
int					ft_lst_del_one(t_head *head, int (*cmp)(void *, void *),
		void *data);
void				ft_lst_del_match(t_head *head, void *data,
		int (*cmp)(void *, void *), void (*del)(void *));
void				ft_lst_del(t_head *head);
int					ft_lst_first_match(t_head *head, void (*cmp)(void),
		void *data);
void				ft_lst_print_elem(t_head *head, void (*print_data),
		void *data);
void				ft_lst_print(t_head *head, void (*print_data));

/*
** ERROR
*/
char	*ft_strerror(void);
char	*ft_strerr(int err);
void	ini_strerror(char ***at);

/*
** OTHERS
*/
int				ft_isnumber(char *str);
char			*ft_strndup(const char *s1, int count);
char			**ft_strsplit_ft(char const *s, int (*f)(int));
int				ft_isblank(int c);
size_t			ft_tablen(char **tabl);
void			ft_puttabl(char **tabl);
char			**ft_tabdup(char **tabl);
t_lst			*ft_creat_list();
t_lst			*ft_add_lst(t_lst *lst, char *str);
t_lst			*ft_find_like(t_lst *lst, char *str);
void			ft_free_lst(t_lst *lst);
int				ft_strprefix(const char *str, const char *prefix);
char			**ft_strsplitwith(char *str, char *seps, size_t *count);
int				ft_min(int x, int y);
char			*ft_ltoa(long long n);
char			*ft_chartostr(const char c);
char			*ft_keepstring(const char c, char *str);
char			*ft_keepstring_inv(const char c, char *str);
int				ft_nbrlen(int nb);
char			*ft_delstr(void);
int				ft_putstr_len(const char *str, int len);
int				ft_putwchar(wint_t x);
int				ft_putwstr(wchar_t *str);
int				ft_lenwchar(wint_t x);
int				ft_lenwstr(wchar_t *str);
t_bool			ft_aisi(const char *s);
int				ft_max(int a, int b);
void			ft_straddchar(char **s, const char c);
char			*ft_ftoa(double n, long prec);
size_t			ft_table_size(void **tbl);
void			ft_table_clear(void ***atbl, void (*del)());
void			ft_strtable_clear(char ***atbl);

# ifndef ERR
#  define __FT0		STDERR_FILENO, "{bold}{red}ERROR {white}%s:%i{reset}\t"
#  define __FT1		__FILE__, __LINE__
#  define ERR(f, ...) ft_dprintf(__FT0 f "\n", __FT1, ##__VA_ARGS__), -1
# endif

#endif
