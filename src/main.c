/*
** main.c for  in /home/munoz_d/Epitech/projets/rendu_PiscineSynthese/SBMLparser/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Jun 13 09:30:29 2016 David Munoz
** Last update Wed Jun 15 18:21:36 2016 David Munoz
*/

#include "utils.h"
#include "parser.h"

int	main(int ac, char **av)
{
  if (ac > 1 && ac < 6)
    {
      if (check_args(ac, av) == SBML_ERR)
	return (84);
      return (SBML_OK);
    }
  else
    return (cerr_zero(ERROR, ERR_USAGE, 84));
}
