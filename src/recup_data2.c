/*
** recup_data.c for  in /home/munoz_d/Bureau/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Jun 14 17:14:27 2016 David Munoz
** Last update Wed Jun 15 10:59:34 2016 David Munoz
*/

#include "utils.h"
#include "parser.h"

void	tab_data_species(t_sbml *sbml, char *data_species, int k)
{
  data_species[k] = 0;
  sbml->data_species = my_str_to_wordtab(data_species, '\n');
  trie_tab(sbml->data_species);
}

int	recup_data_species(t_sbml *sbml, int y)
{
  char  *data_species;
  int   k;
  int   x;

  if ((data_species=malloc((sizeof(char*)*my_strlen_tab(sbml->tab))+1)) == NULL)
    return (cerr_zero(ERROR, ERR_MALL, SBML_ERR));
  k = 0;
  while (sbml->tab[y++][0] != '/')
    {
      x = -1;
      while (sbml->tab[y][++x] && sbml->tab[y][x] != '/')
        {
          if (sbml->tab[y][x+1] == '\0')
            {
              data_species[k] = sbml->tab[y][x];
              k++;
              data_species[k++] = '\n';
            }
          else
            data_species[k++] = sbml->tab[y][x];
        }
    }
  tab_data_species(sbml, data_species, k);
  free(data_species);
  return (SBML_OK);
}

void	tab_data_compart(t_sbml *sbml, char *data_compart, int k)
{
  data_compart[k] = 0;
  sbml->data_compart = my_str_to_wordtab(data_compart, '\n');
  trie_tab(sbml->data_compart);
}

int	recup_data_compart(t_sbml *sbml, int y)
{
  char	*data_compart;
  int	k;
  int	x;

  if ((data_compart=malloc((sizeof(char*)*my_strlen_tab(sbml->tab))+1)) == NULL)
    return (-1);
  k = 0;
  while (sbml->tab[y++][0] != '/')
    {
      x = -1;
      while (sbml->tab[y][++x] && sbml->tab[y][x] != '/')
        {
          if (sbml->tab[y][x+1] == '\0')
            {
              data_compart[k] = sbml->tab[y][x];
              k++;
              data_compart[k++] = '\n';
            }
          else
            data_compart[k++] = sbml->tab[y][x];
        }
    }
  tab_data_compart(sbml, data_compart, k);
  free(data_compart);
  return (SBML_OK);
}
