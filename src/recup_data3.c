/*
** recup_data3.c for  in /home/munoz_d/Bureau/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed Jun 15 09:36:15 2016 David Munoz
** Last update Wed Jun 15 11:00:11 2016 David Munoz
*/

#include "parser.h"
#include "utils.h"

void	tab_data_speciesRef(t_sbml *sbml, char *data_speciesRef, int k)
{
  data_speciesRef[k] = 0;
  sbml->data_speciesRef = my_str_to_wordtab(data_speciesRef, '\n');
  trie_tab(sbml->data_speciesRef);
}

int	recup_data_speciesRef(t_sbml *sbml, int y)
{
  char  *data_speRef;
  int   k;
  int   x;

  if ((data_speRef=malloc((sizeof(char*)*my_strlen_tab(sbml->tab))+1)) == NULL)
    return (cerr_zero(ERROR, ERR_MALL, SBML_ERR));
  k = 0;
  while (sbml->tab[y++][0] != '/')
    {
      x = -1;
      while (sbml->tab[y][++x] && sbml->tab[y][x] != '/')
        {
          if (sbml->tab[y][x+1] == '\0')
            {
              data_speRef[k] = sbml->tab[y][x];
              k++;
              data_speRef[k++] = '\n';
            }
          else
            data_speRef[k++] = sbml->tab[y][x];
        }
    }
  tab_data_speciesRef(sbml, data_speRef, k);
  free(data_speRef);
  return (SBML_OK);
}

void	tab_data_reaction(t_sbml *sbml, char *data_reaction, int k)
{
  data_reaction[k] = 0;
  sbml->data_reaction = my_str_to_wordtab(data_reaction, '\n');
  trie_tab(sbml->data_reaction);
}

int	recup_data_reaction(t_sbml *sbml, int y)
{
  char  *data_reaction;
  int   k;
  int   x;

  if ((data_reaction=malloc((sizeof(char*)*my_strlen_tab(sbml->tab))+1))== NULL)
    return (-1);
  k = 0;
  while (sbml->tab[y++][0] != '>')
    {
      x = -1;
      while (sbml->tab[y][++x] && sbml->tab[y][x] != '>')
        {
          if (sbml->tab[y][x+1] == '\0')
            {
              data_reaction[k] = sbml->tab[y][x];
              k++;
              data_reaction[k++] = '\n';
            }
          else
            data_reaction[k++] = sbml->tab[y][x];
        }
    }
  tab_data_reaction(sbml, data_reaction, k);
  free(data_reaction);
  return (SBML_OK);
}
