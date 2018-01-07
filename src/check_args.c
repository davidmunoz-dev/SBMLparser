/*
** main.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Jun 13 09:30:29 2016 David Munoz
** Last update Wed Jun 15 16:20:14 2016 David Munoz
*/

#include "utils.h"
#include "parser.h"

void	print_help()
{
  my_putstr(GREEN"USAGE\t");
  my_putstr("\t./SBMLparser SBMLfile [-i ID [-e]] [-json]\n\n"BLANK);
  my_putstr("\tSBMLfileSBML file\n");
  my_putstr("\t-i ID\tid of the compartment, ");
  my_putstr("reaction or product to be extracted (ignored if uncorrect)\n");
  my_putstr("\t-e\tprint the equation if reaction ID is given as argmt\n");
  my_putstr("\t-json\ttransform the file into a JSON file\n");
}

int	two_args(char **av)
{
  t_sbml	*sbml;

  if (my_strcmp(av[1], "-h") == SBML_OK)
    {
      print_help();
      return (SBML_OK);
    }
  else if (my_strstr(av[1], ".sbml") != NULL)
    {
      if ((sbml = malloc(sizeof(t_sbml))) == NULL)
	return (cerr_zero(ERROR, ERR_MALL, SBML_ERR));
      memset(sbml, 0, sizeof(t_sbml));
      if (init_struct(sbml, av) == SBML_ERR)
	return (SBML_ERR);
      return (SBML_OK);
    }
  else if (my_strcmp(av[1], "-json") == SBML_OK)
    {
      printf("Not done yet\n");
      return (SBML_OK);
    }
  return (cerr_zero(ERROR, ERR_USAGE, SBML_ERR));
}

int	three_args(char **av)
{
  t_sbml	*sbml;

  if (my_strstr(av[1], ".sbml") != NULL)
    {
      if (my_strcmp(av[2], "-i") == SBML_OK)
	{
	  if ((sbml = malloc(sizeof(t_sbml))) == NULL)
	    return (cerr_zero(ERROR, ERR_MALL, SBML_ERR));
	  memset(sbml, 0, sizeof(t_sbml));
	  if (init_struct_option_i(sbml, av) == SBML_ERR)
	    return (SBML_ERR);
	  return (SBML_OK);
	}
    }
  return (SBML_ERR);
}

int	option(char **av)
{
  if (my_strcmp(av[4], "-e") == SBML_OK
      || my_strcmp(av[4], "-json") == SBML_OK)
    return (SBML_OK);
  return (SBML_ERR);
}

/*
** Gerer ./SBML -i ok
*/

int	check_args(int ac, char **av)
{
  if (ac == 2)
    {
      if (two_args(av) == SBML_ERR)
	return (SBML_ERR);
    }
  else if (ac == 4 || ac == 3)
    {
      if (three_args(av) == SBML_ERR)
	return (SBML_ERR);
    }
  else if (ac == 5)
    {
      if (three_args(av) == SBML_ERR
	  || option(av) ==SBML_ERR)
	return (SBML_ERR);
    }
  else if (ac == 6)
    {
      if (three_args(av) == SBML_ERR
	   || option(av) == SBML_ERR
	   || my_strcmp(av[5], "-json") == 1)
	return (SBML_ERR);
    }
  return (SBML_OK);
}
