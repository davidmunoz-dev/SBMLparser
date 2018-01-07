/*
** my_str_isalpha.c for isalpha in /home/munoz_d/rendu/Piscine_C_J07/lib/my
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Oct  6 11:43:05 2015 munoz david
** Last update Wed Jun 15 10:10:55 2016 David Munoz
*/

#include "my.h"

int	my_str_islphanumore(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')
	  && (str[i] < '0' || str[i] > '9') && str[i] != '_' && str[i] != '-')
	return (0);
      i = i + 1;
    }
  return (1);
}
