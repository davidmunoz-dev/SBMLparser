/*
** flag3.c for flag3 in /rendu_Systeme_Unix/PSU_2015_my_printf/src
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Nov 12 10:45:08 2015 munoz david
** Last update Wed Jun  8 16:15:43 2016 David Munoz
*/

#include <stdarg.h>
#include "../my.h"

void	octal(va_list ap)
{
  my_printf_octal(va_arg(ap, unsigned int));
}

void	bin(va_list ap)
{
  my_put_base(va_arg(ap, unsigned int), "01");
}

void	percent()
{
  my_putchar('%');
}
