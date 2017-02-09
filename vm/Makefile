# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 16:28:28 by tettouat          #+#    #+#              #
#    Updated: 2017/02/09 17:01:57 by tettouat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../corewar

FLAGS		=	-Wall -Wextra -Werror

SRCDIR		=	srcs/

INCDIR		=	includes/

OBJDIR		=	objs/

MLX_DIR		=	../minilibx_macos/

MLX_FLAGS_O	=	-L ./$(MLX_DIR) -framework OPENGL -framework AppKit -lmlx

LIBFT_DIR	=	../libft/

LIBXFT_DIR	=	libxft/

LIBFT_LIB	=	$(LIBFT_DIR)libft.a

LIBXFT_LIB	=	$(LIBXFT_DIR)libxft.a

SRC			=	corewar.c \
				cycle.c \
				dump.c \
				file/check.c \
				file/get_header.c \
				file/read.c \
				func_tab.c \
				func_verbose_tab.c \
				main.c \
				mlx/draw/background.c \
				mlx/draw/info.c \
				mlx/draw/memory.c \
				mlx/draw/rect.c \
				mlx/keys/esc.c \
				mlx/keys/s.c \
				mlx/keys/space.c \
				mlx/keys/suppr.c \
				mlx/launch.c \
				mlx/loop_hook.c \
				mlx/mlx_init.c \
				mlx/threads/info.c \
				mlx/threads/memory.c \
				op/add.c \
				op/aff.c \
				op/and.c \
				op/byte_code_to_type.c \
				op/check_type_args.c \
				op/fork.c \
				op/ld.c \
				op/ldi.c \
				op/lfork.c \
				op/live.c \
				op/lld.c \
				op/lldi.c \
				op/or.c \
				op/st.c \
				op/sti.c \
				op/sub.c \
				op/xor.c \
				op/zjmp.c \
				op_tab.c \
				option.c \
				player/creat.c \
				process/action.c \
				process/check_live.c \
				process/creat.c \
				process/fork.c \
				process/jump.c \
				ram/get_values.c \
				ram/ini_ram.c \
				ram/set_values.c \
				sgt/sgt_corewar.c \
				sgt/sgt_mlx.c \
				thread/launch.c \
				thread/vm.c \
				usage.c \
				verbosity/cycle.c \
				verbosity/cycle_to_die.c \
				verbosity/death.c \
				verbosity/live.c \
				verbosity/move.c \
				verbosity/op/add.c \
				verbosity/op/aff.c \
				verbosity/op/and.c \
				verbosity/op/fork.c \
				verbosity/op/ld.c \
				verbosity/op/ldi.c \
				verbosity/op/lfork.c \
				verbosity/op/live.c \
				verbosity/op/lld.c \
				verbosity/op/lldi.c \
				verbosity/op/or.c \
				verbosity/op/st.c \
				verbosity/op/sti.c \
				verbosity/op/sub.c \
				verbosity/op/xor.c \
				verbosity/op/zjmp.c \
				verbosity/op.c \
				win.c

SRCS =	$(addprefix $(SRCDIR), $(SRC))

OBJ	= $(addprefix $(OBJDIR), $(SRC:.c=.o))

all:		$(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(dir $(OBJ))

$(OBJDIR)%.o : $(SRCDIR)%.c | $(OBJDIR)
	@gcc $(FLAGS) -c $< -o $@												\
		-I $(LIBFT_DIR)$(INCDIR)											\
		-I $(LIBXFT_DIR)$(INCDIR)											\
		-I $(MLX_DIR)														\
		-I $(INCDIR)

$(NAME):	$(OBJDIR) $(OBJ)
	@make -j -C $(MLX_DIR)
	@make -j -C $(LIBFT_DIR)
	@make -j -C $(LIBXFT_DIR)
	@gcc $(FLAGS) $(MLX_FLAGS_O) -o $(NAME) $(OBJ)							\
		$(LIBFT_LIB)														\
		$(LIBXFT_LIB)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBXFT_DIR) clean
	if [[ -d $(OBJDIR) ]]; then rm -r $(OBJDIR); fi

fclean:	clean
	@make -C $(MLX_DIR) clean
	@rm -f $(NAME)

re:	fclean all


.PHONY: fclean clean re 

.SILENT: clean