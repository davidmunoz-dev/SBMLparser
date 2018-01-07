/*
** fonction2.c for pointeur_fonction in /PSU_2015_my_printf/src
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Nov 12 10:27:48 2015 munoz david
** Last update Wed Jun  8 16:15:36 2016 David Munoz
*/

#include <stdarg.h>
#include "../my.h"

void	min_hexa(va_list ap)
{
  my_put_base(va_arg(ap, unsigned int), "0123456789abcdef");
}

void	maj_hexa(va_list ap)
{
  my_put_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
}

void	unsign(va_list ap)
{
  my_put_unsign(va_arg(ap, unsigned int));
}

void	hexa_p(va_list ap)
{
  my_putstr("0x");
  my_adresse(va_arg(ap, int), "0123456789abcdef");
}

void	maj_s(va_list ap)
{
  my_S(va_arg(ap, char *));
}
