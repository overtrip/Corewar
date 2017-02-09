# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/30 11:06:29 by tettouat          #+#    #+#              #
#    Updated: 2017/02/09 16:24:21 by tettouat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

FLAG =	-Wall -Wextra -Werror

SRCDIR = srcs/

INCDIR = includes/

OBJDIR = objs/

SRC =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		get_next_line.c \
		lstd_back.c	\
		lstd_clear.c \
		lstd_del.c \
		lstd_do.c \
		lstd_front.c \
		lstd_get_last.c \
		lstd_map.c \
		lstd_new.c \
		lstd_pop_back.c \
		lstd_pop_front.c \
		lstd_push_after.c \
		lstd_push_back.c \
		lstd_push_before.c \
		lstd_push_cond.c \
		lstd_push_front.c \
		lstd_rmap.c \
		lstd_size.c \
		ft_list_push_back.c \
		ft_lst_create_no_malloc.c \
		ft_lst_del_match.c \
		ft_lst_del.c \
		ft_lst_foreach.c \
		ft_lst_init_head.c \
		ft_lst_match.c \
		ft_lst_pop.c \
		ft_lst_push_back.c \
		ft_lst_push_front.c \
		ini_strerror.c \
		ft_strerror.c \
		ft_isnumber.c \
		ft_strndup.c \
		ft_strsplit_ft.c \
		ft_isblank.c \
		ft_tablen.c \
		ft_tabdup.c \
		ft_puttab.c \
		ft_list.c \
		ft_strprefix.c \
		ft_strsplitwith.c \
		ft_min.c \
		ft_ltoa.c \
		ft_chartostr.c \
		ft_keepstring.c \
		ft_keepstring_inv.c \
		ft_nbrlen.c \
		ft_delstr.c \
		ft_putstr_len.c \
		ft_putwchar.c \
		ft_putwstr.c \
		ft_lenwchar.c \
		ft_lenwstr.c \
		ft_aisi.c \
		ft_max.c \
		ft_straddchar.c \
		ft_ftoa.c \
		ft_table_size.c \
		ft_table_clear.c \
		ft_strtable_clear.c \
		ft_printf/add/add_char.c \
		ft_printf/add/add_string.c \
		ft_printf/add/add_wchar.c \
		ft_printf/add/fill_character.c \
		ft_printf/color/color_basic.c \
		ft_printf/color/color_fg_bg.c \
		ft_printf/color/color_format.c \
		ft_printf/color/concat.c \
		ft_printf/color/replace_color.c \
		ft_printf/conversion/b.c \
		ft_printf/conversion/big_d.c \
		ft_printf/conversion/c.c \
		ft_printf/conversion/f.c \
		ft_printf/conversion/i.c \
		ft_printf/conversion/o.c \
		ft_printf/conversion/p.c \
		ft_printf/conversion/s.c \
		ft_printf/conversion/u.c \
		ft_printf/conversion/x.c \
		ft_printf/flags/flags.c \
		ft_printf/flags/modifiers.c \
		ft_printf/format.c \
		ft_printf/function_conversion.c \
		ft_printf/init/ini_printf.c \
		ft_printf/label/number.c \
		ft_printf/label/number2.c \
		ft_printf/label/number_left.c \
		ft_printf/label/string.c \
		ft_printf/label/wstr_to_str.c \
		ft_printf/ft_printf.c

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(dir $(OBJ))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	@gcc $(FLAGS) -c $< -o $@ -I $(INCDIR)

$(NAME): $(OBJDIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	if [[ -d $(OBJDIR) ]]; then rm -r $(OBJDIR); fi

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re

.SILENT: clean