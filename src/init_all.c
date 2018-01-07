/*
** init_all.c for  in /home/munoz_d/Bureau/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Jun 14 11:38:26 2016 David Munoz
** Last update Wed Jun 15 13:02:24 2016 David Munoz
*/

#include "parser.h"
#include "utils.h"

int	simple_parser(char **av, t_sbml *sbml)
{
  struct stat	sb;
  FILE	*fichier;
  char  *str;
  char  *tmp;
  int	i;

  i = 0;
  if (stat(av[1], &sb) == SBML_ERR)
    return (cerr_zero(ERROR, ERR_OPEN, SBML_ERR));
  if ((str = malloc(sb.st_size)) == NULL
      || (fichier = fopen(av[1], "r")) == NULL)
    return (cerr_zero(ERROR, ERR_OPEN, SBML_ERR));
  while (fgets(str, sb.st_size, fichier) != NULL)
    {
      if (i == 1)
        tmp = my_fusion_str(tmp, str);
      else
        {
          tmp = my_strdup(str);
          i = 1;
        }
    }
  sbml->tab = my_strtowordtab_synthesis(tmp);
  fclose(fichier);
  return (SBML_OK);
}

int	init_struct(t_sbml *sbml, char **av)
{
  if (simple_parser(av, sbml) == SBML_ERR)
    return (SBML_ERR);
  if ((sbml->balise = malloc((sizeof(sbml->balise)
			      * my_strlen_tab(sbml->tab)) + 1)) == NULL)
    return (SBML_ERR);
  if (recup_balise(sbml) == SBML_ERR)
    return (SBML_ERR);
  sbml->balise = trie_tab(sbml->balise);
  sbml->tmp =  delete_double(sbml->balise);
  free_tab(sbml->tab);
  print_result(sbml);
  return (0);
}
