/*
** my_strdup.c for  in /home/munoz_d/Bureau/SBMLparser/lib/my
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Jun 14 09:21:50 2016 David Munoz
** Last update Tue Jun 14 09:23:36 2016 David Munoz
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char		*my_strdup(char *str)
{
  char  *dest;

  if (!(dest = (char *)malloc(sizeof(char) * my_strlen(str) + 1)))
    return (NULL);
  dest = my_strcpy(dest, str);
  dest[my_strlen(str)] = 0;
  return (dest);
}
