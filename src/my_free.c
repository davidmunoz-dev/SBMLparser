/*
** my_free.c for  in /home/munoz_d/Bureau/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed Jun 15 00:39:31 2016 David Munoz
** Last update Wed Jun 15 00:39:40 2016 David Munoz
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab[i]);
  free(tab);
}
