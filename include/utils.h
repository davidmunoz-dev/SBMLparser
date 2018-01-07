/*
** dante.h for  in /include
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu May  5 12:32:55 2016 David Munoz
** Last update Wed Jun 15 18:01:27 2016 David Munoz
*/

#ifndef UTILS_H_
# define UTILS_H_

/*
** Include header files
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

/*
** Color macro definition
*/
# define RED                    "\033[1;31m"
# define GREEN                  "\033[1;32m"
# define PURPLE                 "\033[1;35m"
# define CYAN                   "\033[1;36m"
# define BROWN                  "\033[0;33m"
# define BLUE                   "\033[1;34m"
# define YELLOW                 "\033[1;33m"
# define BLANK                  "\033[0m"

/*
** Error macro definition
*/
# define	ERROR			RED"Error "BLANK
# define	ERR_USAGE		RED"on usage\nUse the parameter '-h' for help\n"BLANK
# define	ERR_MALL		RED": Malloc failed\n"BLANK
# define	ERR_OPEN		RED": Open failed\n"BLANK
# define	ERR_FILE		RED": Wrong file\n"BLANK

/*
** Macro definition
*/
# define	SBML_OK		0
# define	SBML_ERR	-1
# define	BUFF_SIZE	4096

#endif /* UTILS_H_ ! */
