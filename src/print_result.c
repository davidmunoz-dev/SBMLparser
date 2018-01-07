/*
** print_result.c for  in /home/munoz_d/Bureau/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed Jun 15 00:15:25 2016 David Munoz
** Last update Wed Jun 15 18:14:56 2016 David Munoz
*/

#include "utils.h"
#include "parser.h"

void	print_tab_end(char **tab)
{
  int   i;
  int   j;

  i = 0;
  while (tab[i])
    {
      j = 0;
      my_putstr("----->");
      while (tab[i][j] != '=')
        {
          my_putchar(tab[i][j]);
          j++;
        }
      my_putchar('\n');
      i++;
    }
}

void	print_result(t_sbml *sbml)
{
  int	i;

  i = 0;
  while (sbml->tmp[i])
    {
      my_putstr(sbml->tmp[i]);
      my_putchar('\n');
      if (my_strcmp(sbml->tmp[i], "compartment") == 0)
	print_tab_end(sbml->data_compart);
      else if (my_strcmp(sbml->tmp[i], "model") == 0)
      	print_tab_end(sbml->data_model);
      else if (my_strcmp(sbml->tmp[i], "reaction") == 0)
      	print_tab_end(sbml->data_reaction);
      else if (my_strcmp(sbml->tmp[i], "sbml") == 0)
      	print_tab_end(sbml->data_sbml);
      else if (my_strcmp(sbml->tmp[i], "species") == 0)
      	print_tab_end(sbml->data_species);
      else if (my_strcmp(sbml->tmp[i], "speciesReference") == 0)
      	print_tab_end(sbml->data_speciesRef);
      i++;
    }
}
