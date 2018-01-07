##
## Makefile for  in /home/munoz_d/test
## 
## Made by David Munoz
## Login   <munoz_d@epitech.net>
## 
## Started on  Thu May 19 09:43:57 2016 David Munoz
## Last update Wed Jun 15 18:41:23 2016 David Munoz
##

TARGET   = SBMLparser

CC       = gcc

SRC	 = main.c		\
	   str_to_wdtab.c	\
	   check_args.c		\
	   my_fusion_str.c	\
	   init_all.c		\
	   init_all_option.c	\
	   utils.c		\
	   recup_data.c		\
	   recup_data2.c	\
	   tri_name.c		\
	   print_result.c	\
	   simple_parser.c	\
	   my_free.c		\
	   recup_data3.c	\
	   wrong_option.c	\
	   option_i.c		\

CFLAGS   = -W -Wall -Werror -ansi -pedantic -Iinclude -g

SRCDIR   = src
OBJDIR   = obj

SOURCES  := $(addprefix src/, $(SRC))

OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

rm	 = rm -rf
mkdir	 = mkdir -p

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) -L./lib/my -lmy
	@echo "\033[0;35m"$(TARGET)"\033[1;32m compilated !\033[0m"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(mkdir) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1;32m  [OK]  \033[1;36m"$<"\033[0m"

all	: $(OBJECTS) $(TARGET)

clean	:
	@$(rm) $(OBJDIR)
	@echo "\033[1;31mBinary files deleted\033[0m"

fclean	: clean
	@$(rm) $(TARGET)
	@echo "\033[1;31mBinary and executable files are deleted\033[0m"

re	: fclean all

.PHONY: all clean fclean re
