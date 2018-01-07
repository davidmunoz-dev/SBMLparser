##
## Makefile for c in /PSU_2015_tetris/lib/my
## 
## Made by David Munoz
## Login   <munoz_d@epitech.net>
## 
## Started on  Tue Mar  1 18:42:18 2016 David Munoz
## Last update Wed Jun 15 10:30:53 2016 David Munoz
##

TARGET	= libmy.a

SOURCES	= my_str_islphanumore.c \
	  my_find_prime_sup.c \
	  my_str_to_wordtab.c \
	  my_strcapitalize.c \
	  my_sort_int_tab.c \
	  my_str_islower.c \
	  my_str_isalpha.c \
	  my_square_root.c \
	  my_str_isupper.c \
	  get_next_line.c \
	  my_strlowcase.c \
	  my_print_tab.c \
	  my_power_rec.c \
	  my_str_isnum.c \
	  my_strupcase.c \
	  my_is_prime.c \
	  my_cerr_err.c \
	  my_put_nbr.c \
	  my_putchar.c \
	  my_realloc.c \
	  my_strncmp.c \
	  my_strncpy.c \
	  my_strdup.c \
	  my_strcat.c \
	  my_strlen.c \
	  my_putstr.c \
	  my_strcpy.c \
	  my_revstr.c \
	  my_getnbr.c \
	  my_strstr.c \
	  my_strcmp.c \
	  my_isneg.c \
	  my_swap.c \
          printf/fonction_flag2.c \
          printf/fonction_flag.c \
          printf/my_printf.c \
          printf/flag3.c \
          printf/flag2.c \
          printf/flag.c

CFLAGS   = -W -Wall -Werror -ansi -pedantic -Iinclude

SRCDIR   = my
OBJDIR   = obj
PRINDIR	 = obj/printf/

OBJECTS  := $(SOURCES:%.c=$(OBJDIR)/%.o)

CCLIB	 = ar rc
RANLIB	 = ranlib
rm       = rm -rf
mkdir    = mkdir -p

$(TARGET): $(OBJECTS)
	@$(CCLIB) $(TARGET) -o $@ $(OBJECTS)
	@$(RANLIB) $(TARGET)
	@cp $(TARGET) ../
	@cp my.h ../../include
	@echo "\033[0;35m"$(TARGET)"\033[1;32m compiled !\033[0m"

$(OBJECTS): $(OBJDIR)/%.o : %.c
	@$(mkdir) $(OBJDIR) $(PRINDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1;32m  [OK]  \033[1;36m"$<"\033[0m"

all     : $(TARGET)

clean   :
	@$(rm) $(OBJDIR)
	@echo "\033[1;31mBinary files deleted\033[0m"

fclean  : clean
	@$(rm) $(TARGET)
	@$(rm) ../$(TARGET)
	@echo "\033[1;31mBinary and executable files have been deleted\033[0m"

re      : fclean all

.PHONY: all clean fclean re
