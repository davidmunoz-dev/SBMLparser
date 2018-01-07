/*
** my_put_nbr.c for Nombre in /home/munoz_d/rendu/Piscine_C_J03
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Oct  6 10:39:16 2015 munoz david
** Last update Tue Feb 23 14:42:59 2016 David Munoz
*/

#include "my.h"

int	my_put_nbr(int nbr)
{
  int   neg;

  neg = 0;
  if (nbr < 0)
    {
      my_putchar('-');
      if (nbr == -2147483648)
        {
          neg = 1;
          nbr++;
        }
      nbr = nbr * -1;
    }
  if (nbr >= 10)
    my_put_nbr(nbr / 10);
  if (neg == 1)
    {
      neg = 0;
      my_putchar(nbr % 10 + '1');
    }
  else
    my_putchar(nbr % 10 + '0');
  return (0);
}
