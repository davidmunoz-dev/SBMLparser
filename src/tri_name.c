/*
** tri_name.c for  in /home/munoz_d/Bureau/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Jun 14 23:53:30 2016 David Munoz
** Last update Wed Jun 15 10:58:50 2016 David Munoz
*/

#include "parser.h"
#include "utils.h"

int	my_strlenghtcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] > s2[i])
        return (1);
      if (s1[i] < s2[i])
        return (-1);
      i++;
    }
  if (my_strlen(s1) > my_strlen(s2))
    return (1);
  if (my_strlen(s1) < my_strlen(s2))
    return (-1);
  return (SBML_OK);
}

char	**trie_tab(char **tab)
{
  int   i;
  char  *tmp;

  i = 0;
  while (tab && tab[i] && tab[i + 1])
    {
      if (my_strlenghtcmp(tab[i], tab[i + 1]) == 1)
        {
          while (tab && tab[i] && tab[i + 1])
            {
              tmp = tab[i];
              tab[i] = tab[i + 1];
              tab[i + 1] = tmp;
              i++;
            }
          i = -1;
        }
      i++;
    }
  return (tab);
}
