/*
** my_strncpy.c for Exercice 3 in /home/munoz_d/rendu/Piscine_C_J06/ex_03
** 
** Made by munoz david
** Login   <munoz_d@epitech.net>
** 
** Started on  Mon Oct  5 11:36:06 2015 munoz david
** Last update Wed Oct  7 21:58:59 2015 munoz david
*/

char	*my_strncpy(char *dest, char *src, int nb)
{
  int	i;

  i = 0;
  while (i < nb && src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
