/*
** my_revstr.c for Exercice 4 in /home/munoz_d/rendu/Piscine_C_J06
** 
** Made by munoz david
** Login   <munoz_d@epitech.net>
** 
** Started on  Mon Oct  5 15:02:18 2015 munoz david
** Last update Thu Oct 22 14:15:04 2015 munoz david
*/

char	*my_revstr(char *str)
{
  int	compt;
  int	c;
  int	i;
  int	a;
  int	b;

  compt = 0;
  i = 0;
  while (str[compt] != '\0')
    {
      compt = compt + 1;
    }
  compt = compt - 1;
  while (i < compt - i)
    {
      a = str[i];
      b = str[compt - i];
      c = a;
      a = b;
      b = c;
      str[i]= a;
      str[compt - i] = b;
      i = i + 1;
    }
  return (str);
}
