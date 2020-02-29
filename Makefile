# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ielmoudn <ielmoudn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 21:40:46 by ielmoudn          #+#    #+#              #
#    Updated: 2020/02/29 10:49:58 by ielmoudn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT_DIRECTORY = ./src/libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

HEADERS_LIST = ft_printf.h
HEADERS_DIRECTORY = ./inc/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./src/
SOURCES_LIST = ft_printf.c\
			init_flags.c\
			is_specifier.c\
			parsers.c\
			parsers2.c\
			process.c\
			wr_char.c\
			wr_str.c\
			utils.c\
			wr_addr.c\
			ft_putchar_count.c\
			wr_int.c\
			append.c\
			wr_o.c\
			wr_u.c\
			wr_float.c\
			bit_shift.c\
			do_dbl.c\
			put_nan.c\
			dbl_fnl.c\
			util1.c\
			conv_utils.c\
			wr_x.c\
			wr_float2.c\
			wr_float3.c\
			add.c\
			libft/ft_atoi.c libft/ft_lstnew.c libft/ft_putnbr.c libft/ft_striter.c libft/ft_strrchr.c\
			libft/ft_bzero.c  libft/ft_memalloc.c libft/ft_putnbr_fd.c libft/ft_striteri.c libft/ft_strsplit.c\
			libft/ft_isalnum.c libft/ft_memccpy.c libft/ft_putstr.c libft/ft_strjoin.c libft/ft_strstr.c\
			libft/ft_isalpha.c libft/ft_memchr.c libft/ft_putstr_fd.c libft/ft_strlcat.c libft/ft_strsub.c\
			libft/ft_isascii.c libft/ft_memcmp.c libft/ft_range.c  libft/ft_strlen.c libft/ft_strtrim.c\
			libft/ft_isdigit.c libft/ft_memcpy.c libft/ft_strcat.c libft/ft_strmap.c libft/ft_tolower.c\
			libft/ft_isprint.c libft/ft_memdel.c libft/ft_strchr.c libft/ft_strmapi.c libft/ft_toupper.c\
			libft/ft_itoa.c libft/ft_memmove.c libft/ft_strclr.c libft/ft_strncat.c libft/ft_ultimate_range.c\
			libft/ft_lstadd.c libft/ft_memset.c libft/ft_strcmp.c libft/ft_strncmp.c libft/safe_malloc.c\
			libft/ft_lstdel.c libft/ft_putchar.c libft/ft_strcpy.c libft/ft_strncpy.c libft/safe_malloc_utils.c\
			libft/ft_lstdelone.c libft/ft_putchar_fd.c libft/ft_strdel.c libft/ft_strnequ.c\
			libft/ft_lstiter.c libft/ft_putendl.c libft/ft_strdup.c libft/ft_strnew.c\
			libft/ft_lstmap.c libft/ft_putendl_fd.c libft/ft_strequ.c libft/ft_strnstr.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
LIBFT_OBJECTS_DIRECTORY = objects/libft/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@mkdir -p $(LIBFT_OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) and $(GREEN)$(LIBFT_OBJECTS_DIRECTORY) were created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@rm -rf $(OBJECTS_DIRECTORY) $(LIBFT_OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) and $(RED)$(LIBFT_OBJECTS_DIRECTORY) were deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	$(MAKE) fclean
	$(MAKE) all
