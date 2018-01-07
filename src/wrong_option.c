/*
** wrong_option.c for  in /home/munoz_d/Bureau/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed Jun 15 16:23:43 2016 David Munoz
** Last update Wed Jun 15 16:39:41 2016 David Munoz
*/

#include "parser.h"
#include "utils.h"

void	print_wrong_option(t_sbml *sbml)
{
  int   i;

  i = 0;
  printf("List of species\n");
  while (sbml->data_species[i])
    {
      printf("----->%s\n", sbml->data_species[i]);
      i++;
    }
}

int	complete_species(t_sbml *sbml, int k, int i, int l)
{
  int   x;

  x = 0;
  if ((sbml->data_species[l] = malloc(my_strlen(sbml->tab[i]) + 1)) == NULL)
    return (SBML_ERR);
  while (sbml->tab[i][k] != 39)
    {
      sbml->data_species[l][x] = sbml->tab[i][k];
      k++;
      x++;
    }
  sbml->data_species[l][x] = 0;
  return (SBML_OK);
}

int	species_init(t_sbml *sbml, int i, int l)
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
          if (complete_species(sbml, k, i, l) == SBML_ERR)
	    return (SBML_ERR);
          return (SBML_OK);
        }
      k++;
    }
  return (SBML_OK);
}

int	wrong_name(t_sbml *sbml)
{
  int   i;
  int   l;

  i = l = 0;
  while (sbml->tab[i] && my_strcmp(sbml->tab[i], "<listOfSpecies>") != 0)
    i++;
  while (sbml->tab[i] && my_strcmp(sbml->tab[i], "</listOfSpecies>") != 0)
    {
      if (my_strncmp(sbml->tab[i], "<species", 8) == 0)
        {
          if (species_init(sbml, i, l) == SBML_ERR)
	    return (SBML_ERR);
          l++;
        }
      i++;
    }
  sbml->data_species[l] = NULL;
  return (SBML_OK);
}

int	bad_option(t_sbml *sbml)
{
  if ((sbml->data_species = malloc
       ((sizeof(sbml->data_species) * my_strlen_tab(sbml->tab)) + 1)) == NULL)
    return (cerr_zero(ERROR, ERR_MALL, SBML_ERR));
  if (wrong_name(sbml) == SBML_ERR)
    return (SBML_ERR);
  trie_tab(sbml->data_species);
  print_wrong_option(sbml);
  return (SBML_OK);
}
