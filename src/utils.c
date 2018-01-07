/*
** utils.c for  in /home/munoz_d/Bureau/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Jun 14 11:27:57 2016 David Munoz
** Last update Wed Jun 15 09:48:36 2016 David Munoz
*/

#include "parser.h"
#include "utils.h"

int	my_strlen_tab(char **str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
