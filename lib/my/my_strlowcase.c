/*
** my_strlowcase.c for lowcase in /home/munoz_d/rendu/Piscine_C_J07/lib/my
** 
** Made by munoz david
** Login   <munoz_d@epitech.net>
** 
** Started on  Tue Oct  6 11:39:18 2015 munoz david
** Last update Thu Oct 22 14:23:05 2015 munoz david
*/

char	*my_strlowcase(char *str)
{
  int	i;

  while (str[i] != '\0')
    {
      if (str[i] > 64 && str[i] < 91)
	str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
