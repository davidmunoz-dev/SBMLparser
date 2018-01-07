/*
** my_realloc.c for  in /home/munoz_d/Epitech/projets/rendu_Systeme_Unix/rendu_ProgShell/PSU_2015_minishell2/lib/my
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed Jun  8 16:05:35 2016 David Munoz
** Last update Mon Jun 13 09:22:08 2016 David Munoz
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char		*my_realloc(char *recup, int ret)
{
  char          *new_str;
  int           i;

  i = 0;
  if ((new_str = malloc(sizeof(char) * ret + my_strlen(recup) + 1)) == NULL)
    return (cerr_msg("Internal error: ", "malloc failed in realloc\n"));
  while (recup[i])
    {
      new_str[i] = recup[i];
      i++;
    }
  new_str[i] = '\0';
  if (my_strcmp(recup, "") != 0)
    free(recup);
  return (new_str);
}
