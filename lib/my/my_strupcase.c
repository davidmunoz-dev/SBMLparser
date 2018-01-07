/*
** my_strupcase.c for upcase in /home/munoz_d/rendu/Piscine_C_J07/lib/my
** 
** Made by munoz david
** Login   <munoz_d@epitech.net>
** 
** Started on  Tue Oct  6 11:38:30 2015 munoz david
** Last update Thu Oct 22 14:22:26 2015 munoz david
*/

char	*my_strupcase(char *str)
{
  int	i;

  while (str[i] != '\0')
    {
      if (str[i] > 96 && str[i] < 123)
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
