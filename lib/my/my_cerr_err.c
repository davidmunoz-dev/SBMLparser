/*
** my_cerr_err.c for  in /home/munoz_d/Epitech/projets/rendu_Systeme_Unix/rendu_ProgShell/PSU_2015_minishell2/lib/my
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed Jun  8 15:52:20 2016 David Munoz
** Last update Wed Jun  8 16:01:24 2016 David Munoz
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	cerr_zero(char *log, char *info, int status)
{
  write(2, log, my_strlen(log));
  write(2, info, my_strlen(info));
  return (status);
}

void	*cerr_msg(char *log, char *info)
{
  write(2, log, my_strlen(log));
  write(2, info, my_strlen(info));
  return (NULL);
}

char	*cerr_null(char *log, char *info)
{
  write(2, log, my_strlen(log));
  write(2, info, my_strlen(info));
  return (NULL);
}
