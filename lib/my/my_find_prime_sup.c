/*
** my_find_prime_sup.c for prime in /home/munoz_d/rendu/Piscine_C_J07/lib/my
** 
** Made by munoz david
** Login   <munoz_d@epitech.net>
** 
** Started on  Tue Oct  6 11:24:23 2015 munoz david
** Last update Thu Oct 22 14:10:38 2015 munoz david
*/

int	my_find_prime_sup(int nb)
{
  int	a;
  int	tmp;

  if (nb == 0 || nb == 1)
    nb = 2;
  a = 2;
  while (a <= nb / 2)
    {
      tmp = nb / a;
      if (a * tmp == nb)
        return (my_find_prime_sup(nb + 1));
      a = a + 1;
    }
  return (nb);
}
