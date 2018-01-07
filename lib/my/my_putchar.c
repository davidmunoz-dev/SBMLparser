/*
** my_putchar.c for putchar in /home/munoz_d/rendu/Piscine_C_J07/lib/my
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Oct  6 11:09:53 2015 munoz david
** Last update Tue Feb 23 14:41:16 2016 David Munoz
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
