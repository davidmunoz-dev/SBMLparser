/*
** requirement.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Jun 13 09:39:22 2016 David Munoz
** Last update Wed Jun 15 09:48:24 2016 David Munoz
*/

#include "utils.h"
#include "parser.h"

int	char_isalpha(char c)
{
  if (c <= 'z' && c >= 'a')
    return (SBML_OK);
  else if (c <= 'Z' && c >= 'A')
    return (SBML_OK);
  else if (c <= '9' && c >= '0')
    return (SBML_OK);
  else if ((c >= '<' && c <= '>') || c == 47 || c == '?')
    return (SBML_OK);
  else
    return (SBML_ERR);
}

int	count_word(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (char_isalpha(str[i]) == SBML_OK)
        {
	  while (char_isalpha(str[i]) == SBML_OK)
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

int	delete_coma(char *str, int i, int x)
{
  if (str[i] == 39 && x == 1)
    x = 0;
  else if (str[i] == 39 && x == 0)
    x = 1;
  return (x);
}

char	**my_strtowordtab_synthesis(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;
  int	x;

  i = j = x = 0;
  if ((tab = malloc((sizeof(tab) * count_word(str)) + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      k = 0;
      if ((tab[j] = malloc((sizeof(tab[j]) * my_strlen(str)) + 1)) == NULL)
	return (NULL);
      if (char_isalpha(str[i]) == 0)
	{
	  while (char_isalpha(str[i]) == 0 || (x = delete_coma(str, i, x)) == 1)
	    tab[j][k++] = str[i++];
	  tab[j++][k + 1] = 0;
	}
      else
	i = check_eof(str, i);
    }
  tab[j] = NULL;
  return (tab);
}
