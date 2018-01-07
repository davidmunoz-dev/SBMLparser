/*
** my_str_islower.c for lower in /home/munoz_d/rendu/Piscine_C_J07/lib/my
** 
** Made by munoz david
** Login   <munoz_d@epitech.net>
** 
** Started on  Tue Oct  6 11:45:41 2015 munoz david
** Last update Thu Oct 22 14:26:41 2015 munoz david
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] < 97 || str[i] > 122)
	return (0);
      i = i + 1;
    }
  return (1);
}
