/*
** my_str_to_wordtab.c for  in /rendu_ProgShell/PSU_2015_minishell2/lib/my
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed Jun  8 15:59:01 2016 David Munoz
** Last update Wed Jun  8 16:00:54 2016 David Munoz
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	cpy_word(char *str, char c)
{
  int	i;
  int	cpy;
  char	prev;

  prev = c;
  i = cpy = 0;
  while (str && str[i])
    {
      if ((prev == c) && (str[i] != c))
	cpy++;
      prev = str[i];
      i++;
    }
  return (cpy);
}

char	*copy(char *str, char *dest, int start, char c)
{
  int	i;

  i = 0;
  while ((str[start] != c) && (str[start]))
    {
      dest[i] = str[start];
      i++;
      start++;
    }
  dest[i] = '\0';
  return (dest);
}

int	cpy_letter(char *str, int start, char c)
{
  int	i;

  i = 0;
  while ((str[start] != c) && (str[start]))
    {
      start++;
      i++;
    }
  return (i);
}

char	**my_str_to_wordtab(char *str, char c)
{
  int	i;
  int	j;
  char	prev;
  char	**tab;

  i = j = 0;
  if ((tab = malloc((cpy_word(str, c) + 1) * sizeof(*tab))) == NULL)
    return (cerr_msg("Internal error :", "Malloc failure\n"));
  prev = c;
  while (str && str[i])
    {
      if ((prev == c) && (str[i] != c))
	{
	  if ((tab[j] = malloc((cpy_letter(str, i, c) + 1) * sizeof(**tab)))
	      == NULL)
	    return (cerr_msg("Internal error :", "Malloc failure\n"));
	  copy(str, tab[j], i, c);
	  j++;
	}
      prev = str[i];
      i++;
    }
  tab[j] = NULL;
  return (tab);
}
