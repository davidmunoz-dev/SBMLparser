/*
** init_all.c for  in /home/munoz_d/Bureau/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Jun 14 11:38:26 2016 David Munoz
** Last update Wed Jun 15 19:11:42 2016 David Munoz
*/

#include "parser.h"
#include "utils.h"

int	simple_parser_option_i(char **av, t_sbml *sbml)
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
  sbml->tab = my_str_to_wordtab(tmp, '\n');
  fclose(fichier);
  return (SBML_OK);
}

int	right_arg(t_sbml *sbml, int i)
{
  int	k;
  int	l;

  k = l = 0;
  while (sbml->tab[i][k])
    {
      if (sbml->tab[i][k] == 'i' && sbml->tab[i][k+1] == 'd'
	  && sbml->tab[i][k+2] == '=' && sbml->tab[i][k+3] == 39)
	{
	  k += 4;
	  while (sbml->tab[i][k] == sbml->file[l])
	    {
	      l++;
	      k++;
	    }
	  if (l == my_strlen(sbml->file))
	    return (SBML_OK);
	  return (SBML_ERR);
	}
      k++;
    }
  return (SBML_ERR);
}

int	right_check(t_sbml *sbml, int i)
{
  if (my_strncmp(sbml->tab[i], "<reaction", 9) == 0)
    return (SBML_OK);
  else if (my_strncmp(sbml->tab[i], "<species", 8) == 0)
    return (SBML_OK);
  else if (my_strncmp(sbml->tab[i], "<compartment", 12) == 0)
    return (SBML_OK);
  return (SBML_ERR);
}

int	check_right_arg(t_sbml *sbml)
{
  int	i;

  i = 0;
  while (sbml->tab[i])
    {
      if (my_strstr(sbml->tab[i], sbml->file) != NULL)
	{
	  if (right_check(sbml, i) == SBML_ERR)
	    return (SBML_ERR);
	  if (right_arg(sbml, i) == SBML_OK)
	    {
	      sbml->x = i;
	      return (SBML_OK);
	    }
	}
      i++;
    }
  return (SBML_ERR);
}

int	init_struct_option_i(t_sbml *sbml, char **av)
{
  if (simple_parser_option_i(av, sbml) == SBML_ERR)
    return (SBML_ERR);
  if ((sbml->balise = malloc((sizeof(sbml->balise)
			      * my_strlen_tab(sbml->tab)) + 1)) == NULL)
    return (cerr_zero(ERROR, ERR_MALL, SBML_ERR));
  if (av[3] != NULL)
    sbml->file = my_strdup(av[3]);
  else
    sbml->file = "";
  if (check_right_arg(sbml) == SBML_ERR)
    {
      if (bad_option(sbml) == SBML_ERR)
	return (SBML_ERR);
      return (SBML_OK);
    }
  if (data_compart(sbml) == SBML_ERR)
    return (SBML_ERR);
  return (SBML_OK);
}
