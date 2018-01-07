/*
** recup_data.c for  in /home/munoz_d/Bureau/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Jun 14 17:14:27 2016 David Munoz
** Last update Wed Jun 15 11:00:00 2016 David Munoz
*/

#include "utils.h"
#include "parser.h"

void	tab_data_sbml(t_sbml *sbml, char *data_sbml, int k)
{
  data_sbml[k] = 0;
  sbml->data_sbml = my_str_to_wordtab(data_sbml, '\n');
  trie_tab(sbml->data_sbml);
}

int	recup_data_sbml(t_sbml *sbml, int y)
{
  char	*data_sbml;
  int	x;
  int	k;

  if ((data_sbml = malloc((sizeof(char*)*my_strlen_tab(sbml->tab))+1)) == NULL)
    return (cerr_zero(ERROR, ERR_MALL, SBML_ERR));
  k = 0;
  while (sbml->tab[y++][0] != '>')
    {
      x = -1;
      while (sbml->tab[y][++x] && sbml->tab[y][x] != '>')
	{
	  if (sbml->tab[y][x+1] == '\0')
	    {
	      data_sbml[k] = sbml->tab[y][x];
	      k++;
	      data_sbml[k++] = '\n';
	    }
	  else
	    data_sbml[k++] = sbml->tab[y][x];
	}
    }
  tab_data_sbml(sbml, data_sbml, k);
  free(data_sbml);
  return (SBML_OK);
}

void	tab_data_model(t_sbml *sbml, char *data_model, int k)
{
  data_model[k] = 0;
  sbml->data_model = my_str_to_wordtab(data_model, '\n');
  trie_tab(sbml->data_model);
}

int	recup_data_model(t_sbml *sbml, int y)
{
  char	*data_model;
  int	k;
  int	x;

  k = 0;
  if ((data_model=malloc((sizeof(char*)*my_strlen_tab(sbml->tab))+1)) == NULL)
    return (cerr_zero(ERROR, ERR_MALL, SBML_ERR));
  while (sbml->tab[y++][0] != '>')
    {
      x = -1;
      while (sbml->tab[y][++x] && sbml->tab[y][x] != '>')
	{
	  if (sbml->tab[y][x+1] == '\0')
	    {
	      data_model[k] = sbml->tab[y][x];
	      k++;
	      data_model[k++] = '\n';
	    }
	  else
	    data_model[k++] = sbml->tab[y][x];
	}
    }
  tab_data_model(sbml, data_model, k);
  free(data_model);
  return (SBML_OK);
}
