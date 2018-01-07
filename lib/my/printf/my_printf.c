/*
** printf.c for printf in rendu_Systeme_Unix/PSU_2015_my_printf/src
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Fri Nov  6 17:33:09 2015 munoz david
** Last update Wed Jun  8 16:15:54 2016 David Munoz
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../my.h"

void	flags(void(*flag[12])(va_list ap))
{
  flag[0] = str;
  flag[1] = bin;
  flag[2] = charact;
  flag[3] = nbr;
  flag[4] = nbr;
  flag[5] = octal;
  flag[6] = min_hexa;
  flag[7] = maj_hexa;
  flag[8] = unsign;
  flag[9] = hexa_p;
  flag[10] = maj_s;
  flag[11] = percent;
}

int	end_line (char *str, int a)
{
  if (str[a + 2] == '\0')
    return (0);
  else
    a = a + 1;
  return (a);
}

int	my_printf(char *str, ...)
{
  void	(*flag[12])(va_list ap);
  va_list	ap;
  char	*list_flag;
  int	b;
  int	a;
  a = -1;
  list_flag = "sbcdioxXupS%";
  flags(flag);
  va_start(ap, *str);
  while (str[++a])
    {
      if (str[a] == '%')
	{
	  b = 0;
	  while (list_flag[b] && str[a + 1] != list_flag[b])
	    b++;
	  if (list_flag[b])
	    flag[b](ap);
	  a = end_line(str, a);
	}
      else
	my_putchar(str[a]);
    }
  va_end(ap);
  return (0);
}
