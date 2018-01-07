/*
** option_i.c for  in /home/munoz_d/Bureau/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed Jun 15 18:27:02 2016 David Munoz
** Last update Wed Jun 15 19:10:53 2016 David Munoz
*/

#include "parser.h"
#include "utils.h"

void	print_compart(t_sbml *sbml)
{
  int   i;

  i = 0;
  printf("List of species in compartment %s\n", sbml->file);
  while (sbml->data_compart[i])
    {
      printf("----->%s\n", sbml->data_compart[i]);
      i++;
    }
}

int	complete_compart(t_sbml *sbml, int k, int i, int l)
{
  int   x;

  x = 0;
  if ((sbml->data_compart[l] = malloc(my_strlen(sbml->tab[i]) + 1)) == NULL)
    return (SBML_ERR);
  while (sbml->tab[i][k] != 39)
    {
      sbml->data_compart[l][x] = sbml->tab[i][k];
      k++;
      x++;
    }
  sbml->data_compart[l][x] = 0;
  return (SBML_OK);
}

int	compart_init(t_sbml *sbml, int i, int l)
{
  int   k;

  k = 0;
  while (sbml->tab[i][k])
    {
      if (sbml->tab[i][k] == 'n' && sbml->tab[i][k+1] == 'a'
          && sbml->tab[i][k+2] == 'm' && sbml->tab[i][k+3] == 'e'
          && sbml->tab[i][k+4] == '=' && sbml->tab[i][k+5] == 39)
        {
          k += 6;
          if (complete_compart(sbml, k, i, l) == SBML_ERR)
            return (SBML_ERR);
          return (SBML_OK);
        }
      k++;
    }
  return (SBML_OK);
}

int	check_species(t_sbml *sbml)
{
  int   i;
  int   l;

  i = l = 0;
  while (sbml->tab[i])
    {
      if (my_strncmp(sbml->tab[i], "<species", 8) == 0)
	{
          if (compart_init(sbml, i, l) == SBML_ERR)
            return (SBML_ERR);
          l++;
	}
      i++;
    }
  sbml->data_compart[l] = NULL;
  return (SBML_OK);
}

int	data_compart(t_sbml *sbml)
{
  if ((sbml->data_compart = malloc
       ((sizeof(sbml->data_compart) * my_strlen_tab(sbml->tab)) + 1)) == NULL)
    return (cerr_zero(ERROR, ERR_MALL, SBML_ERR));
  if (check_species(sbml) == SBML_ERR)
    return (SBML_ERR);
  trie_tab(sbml->data_compart);
  print_compart(sbml);
  return (SBML_OK);
}
