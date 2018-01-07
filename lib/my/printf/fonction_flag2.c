/*
** fonction_flag2.c for lol in /home/munoz_d/PSU_2015_my_printf/src
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Fri Nov 13 18:50:36 2015 munoz david
** Last update Wed Jun  8 16:15:09 2016 David Munoz
*/

#include <stdarg.h>
#include "../my.h"

int	my_adresse(int nb, char *base)
{
  int	b;
  int	str;

  str = my_strlen(base);
  if (nb < 0)
    nb = -nb;
  if (nb >= str)
    {
      b = nb / str;
      my_adresse(b, base);
    }
  my_putchar(base[nb % str]);
  return (0);
}
