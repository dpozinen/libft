#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpozinen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 16:32:03 by dpozinen          #+#    #+#              #
#    Updated: 2017/11/15 16:37:51 by dpozinen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
FLAGS = -Wall -Werror -Wextra -I

LIBSRCS = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_strlen.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
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
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strncpy.c \
		ft_isascii.c \
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
		ft_putchar_fd.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_num_strlen.c \
		ft_number_size.c \
		ft_print_list.c \
		ft_f_lstdel.c \
		free_char_array.c \
		ft_freedup.c \
		get_next_line.c \
		free_n_join.c \
		string_to_upper.c \
		find_not_c.c \
		ft_insert_string.c \
		get_char_index.c \
		put_while_not_c.c \
		make_s_of_chars.c
PRINTSRCS = ft_main_printf.c \
			ft_printf.c \
			add_width_precision_length.c \
			make_and_put_return_string.c \
			make_char_types.c \
			make_flags.c \
			make_signed.c \
			make_unicode.c \
			make_unsigned.c \
			make_width_precision_length.c


OBJDIR = objects

PRINTOBJS = $(addprefix $(OBJDIR)/, $(PRINTSRCS:.c=.o))
LIBOBJS = $(addprefix $(OBJDIR)/, $(LIBSRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJDIR) $(LIBOBJS) $(PRINTOBJS)
	@echo "made object files"
	@ar rc libft.a $(PRINTOBJS) $(LIBOBJS)
	@echo "made $(NAME)"

$(LIBOBJS) : $(OBJDIR)/%.o : %.c
	@gcc $(FLAGS) libft.h -c $< -o $@

$(PRINTOBJS) : $(OBJDIR)/%.o : ft_printf/%.c
	@gcc $(FLAGS) ft_printf/ft_printf.h -c $< -o $@
	
$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -f $(PRINTOBJS)
	@rm -f $(LIBOBJS)
	@rm -rf $(OBJDIR)
	@echo "removed object files and folder"

fclean: clean
	@rm $(NAME)
	@echo "removed $(NAME)"

re: fclean all
