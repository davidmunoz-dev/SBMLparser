/*
** simple_parser.c for  in /home/munoz_d/Bureau/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed Jun 15 09:19:01 2016 David Munoz
** Last update Wed Jun 15 09:48:18 2016 David Munoz
*/

#include "utils.h"
#include "parser.h"

char	**delete_double(char **tab)
{
  char  **new;
  int   i;
  int   k;

  i = k = 0;
  if ((new = malloc((sizeof(new) * my_strlen_tab(tab)) + 1)) == NULL)
    return (NULL);
  while (tab[i])
    {
      new[k] = my_strdup(tab[i]);
      while (tab[i + 1] && my_strcmp(tab[i], tab[i + 1]) == 0)
        i++;
      k++;
      i++;
    }
  new[k] = 0;
  return (new);
}

int	end_list_del(char **tab, int y, t_sbml *sbml)
{
  if (strncmp(tab[y], "<species", 8) == 0)
    {
      if ((recup_data_species(sbml, y)) == SBML_ERR)
        return (SBML_ERR);
      return (SBML_OK);
    }
  else if (strncmp(tab[y], "<reaction", 9) == 0)
    {
      if ((recup_data_reaction(sbml, y)) == SBML_ERR)
        return (SBML_ERR);
      return (SBML_OK);
    }
  else if (strncmp(tab[y], "<compartment", 12) == 0)
    {
      if ((recup_data_compart(sbml, y)) == SBML_ERR)
        return (SBML_ERR);
      return (SBML_OK);
    }
  return (SBML_ERR);
}

int	delete_lists(char **tab, int y, t_sbml *sbml)
{
  if (strncmp(tab[y], "<sbml", 5) == 0)
    {
      if ((recup_data_sbml(sbml, y)) == SBML_ERR)
        return (SBML_ERR);
      return (SBML_OK);
    }
  else if (strncmp(tab[y], "<model", 6) == 0)
    {
      if ((recup_data_model(sbml, y)) == SBML_ERR)
        return (SBML_ERR);
      return (SBML_OK);
    }
  else if (strncmp(tab[y], "<speciesReference", 17) == 0)
    {
      if ((recup_data_speciesRef(sbml, y)) == SBML_ERR)
        return (SBML_ERR);
      return (SBML_OK);
    }
  else if (end_list_del(tab, y, sbml) == SBML_OK)
    return (SBML_OK);
  return (SBML_ERR);
}

int	recup_balise(t_sbml *sbml)
{
  int   y;
  int   x;
  int   i;
  int   j;

  i = y = 0;
  while (sbml->tab[y])
    {
      j = x = 0;
      if (sbml->tab[y][x] && delete_lists(sbml->tab, y, sbml) == SBML_OK)
	{
          if ((sbml->balise[i] = malloc((sizeof(sbml->balise[i])
					 * my_strlen(sbml->tab[y])) + 1)) == NULL)
            return (cerr_zero(ERROR, ERR_MALL, SBML_ERR));
          while (sbml->tab[y][x])
	    sbml->balise[i][j++] = sbml->tab[y][++x];
          sbml->balise[i][x] = 0;
          i++;
        }
      y++;
    }
  sbml->balise[i] = NULL;
  return (SBML_OK);
}
