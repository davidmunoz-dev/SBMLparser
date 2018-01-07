/*
** requirement.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Jun 13 09:39:22 2016 David Munoz
** Last update Tue Jun 14 15:09:58 2016 David Munoz
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	char_isalpha(char c)
{
  if (c <= 'z' && c >= 'a')
    return (0);
  else if (c <= 'Z' && c >= 'A')
    return (0);
  else if (c <= '9' && c >= '0')
    return (0);
  else
    return (-1);
}

int	count_word(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (char_isalpha(str[i]) == 0)
        {
	  while (char_isalpha(str[i]) == 0)
	    i++;
	  j++;
	}
      else
	i++;
    }
  return (j);
}

int	check_eof(char *str, int i)
{
  if (str[i] != '\0')
    i++;
  return (i);
}

char	**my_strtowordtab_synthesis(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = j = 0;
  if ((tab = malloc((sizeof(tab) * count_word(str)) + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      k = 0;
      if ((tab[j] = malloc((sizeof(tab[j]) * my_strlen(str)) + 1)) == NULL)
	return (NULL);
      if (char_isalpha(str[i]) == 0)
	{
	  while (char_isalpha(str[i]) == 0)
	    tab[j][k++] = str[i++];
	  tab[j++][k+1] = '\0';
	}
      else
	i = check_eof(str, i);
    }
  tab[j] = NULL;
  return (tab);
}
