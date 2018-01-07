/*
** fonction.c for pointeur_fonction in /PSU_2015_my_printf/src
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Nov 12 10:27:05 2015 munoz david
** Last update Wed Jun  8 16:15:30 2016 David Munoz
*/

#include <stdarg.h>
#include "../my.h"

void	str(va_list ap)
{
  my_putstr(va_arg(ap, char *));
}

void	charact(va_list ap)
{
  my_putchar((char)va_arg(ap, int));
}

void	nbr(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
}
