# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 16:12:00 by tettouat          #+#    #+#              #
#    Updated: 2017/01/30 16:12:21 by tettouat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libxft.a

FLAGS	=	-Wall -Wextra -Werror

SRCDIR	=	srcs/

INCDIR	=	includes/

OBJDIR	=	objs/

MLX_DIR	=	../../minilibx_macos/

SRC =		color_to_int.c \
			destroy_image.c \
			draw_circle_to_image.c \
			draw_line_to_image.c \
			draw_square_to_image.c \
			func_key.c \
			get_color_in_image.c \
			image_fill.c \
			image_to_image.c \
			image_to_image_png.c \
			int_to_color.c \
			new_image.c \
			put_pixel_to_image.c \
			string_to_image.c \
			xpm_file_to_image.c

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(dir $(OBJ))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	@gcc $(FLAGS) -c $< -o $@ -I $(INCDIR) -I $(MLX_DIR)

$(NAME): $(OBJDIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	if [[ -d $(OBJDIR) ]]; then rm -r $(OBJDIR); fi

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re

.SILENT:clean