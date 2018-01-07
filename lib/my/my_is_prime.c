/*
** my_is_prime.c for Prime in /home/munoz_d/rendu/Piscine_C_J07/lib/my
** 
** Made by munoz david
** Login   <munoz_d@epitech.net>
** 
** Started on  Tue Oct  6 11:26:32 2015 munoz david
** Last update Wed Nov  4 09:54:38 2015 munoz david
*/

int	my_is_prime(int nb)
{
  int	a;
  int	tmp;

  if (nb == 0 || nb == 1)
    return (0);
  a = 2;
  while (a < nb / 2)
    {
      tmp = nb / a;
      if (a * tmp == nb)
	return (0);
      a = a + 1;
    }
  return (1);
}
