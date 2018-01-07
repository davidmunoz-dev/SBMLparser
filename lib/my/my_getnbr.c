/*
** my_getnbr.c for getnumber in /home/munoz_d/rendu/Piscine_C_J07/lib/my
** 
** Made by munoz david
** Login   <munoz_d@epitech.net>
** 
** Started on  Tue Oct  6 12:20:55 2015 munoz david
** Last update Sun Dec 20 22:40:26 2015 Munoz David
*/

#include <stdio.h>

int	my_getnbr(char *str)
{
  int   i;
  int   nbr;
  int   neg;

  i = 0;
  nbr = 0;
  neg = 1;
  if (str == NULL)
    return (0);
  while (str[i] == '-')
    {
      neg = neg * -1;
      i++;
    }
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
        return (nbr * neg);
      nbr = nbr * 10 + (str[i] - '0');
      i++;
    }
  return (nbr * neg);
}
