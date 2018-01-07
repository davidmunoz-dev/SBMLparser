/*
** my_square_root.c for square in /home/munoz_d/rendu/Piscine_C_J07/lib/my
** 
** Made by munoz david
** Login   <munoz_d@epitech.net>
** 
** Started on  Tue Oct  6 11:22:27 2015 munoz david
** Last update Thu Oct 22 14:13:20 2015 munoz david
*/

int	my_square_root(int nb)
{
  int	a;

  a = 0;
  while (a * a != nb)
    {
      a = a + 1;
      if (a == nb / 2 + 1)
	return (0);
    }
  return (a);
}
