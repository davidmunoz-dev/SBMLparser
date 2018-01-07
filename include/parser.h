/*
** SBMLparser.h for  in /home/munoz_d/Bureau/SBMLparser/include
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed Jun 15 09:46:35 2016 David Munoz
** Last update Wed Jun 15 18:54:52 2016 David Munoz
*/

#ifndef PARSER_
# define PARSER_

# define	COMPART		"compartment"
# define	SPECIES		"species"
# define	REACTION	"reaction"

typedef struct s_sbml
{
  char	**tab;
  char	**balise;
  char	**tmp;
  char	**data_sbml;
  char	**data_species;
  char	**data_speciesRef;
  char	**data_compart;
  char	**data_model;
  char	**data_reaction;
  char	*file;
  int	x;
  int	k;
}		t_sbml;

/*
** Simple parser
*/
int     char_isalpha(char c);
int     count_word(char *str);
char    **my_strtowordtab_synthesis(char *str);
void	print_help();
int	two_args(char **av);
int	check_args(int ac, char **av);
char    *my_fusion_str(char *str1, char *str2);
int     my_strlen_tab(char **str);
int	init_struct(t_sbml *sbml, char **av);
int     simple_parser(char **av, t_sbml *sbml);
int     recup_balise(t_sbml *sbml);
int     delete_lists(char **tab, int y, t_sbml *sbml);
int     pars_order_alpha(t_sbml *sbml);
int     recup_data_sbml(t_sbml *sbml, int y);
int     recup_data_model(t_sbml *sbml, int y);
int     recup_data_species(t_sbml *sbml, int y);
int     recup_data_speciesRef(t_sbml *sbml, int y);
int     recup_data_reaction(t_sbml *sbml, int y);
int     recup_data_compart(t_sbml *sbml, int y);
int     my_strrealcmp(char *s1, char *s2);
char    **trie_tab(char **tab);
void    print_result(t_sbml *sbml);
char    **delete_double(char **tab);
void	free_tab(char **tab);

/*
** Option i
*/
int     simple_parser_option_i(char **av, t_sbml *sbml);
int     init_struct_option_i(t_sbml *sbml, char **av);
int     bad_option(t_sbml *sbml);
int     recup_data(t_sbml *sbml);
int     data_compart(t_sbml *sbml);


#endif /* !PARSER_ */
