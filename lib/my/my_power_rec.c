/*
** my_power_rec.c for Exercice 4 in /home/munoz_d/rendu/Piscine_C_J05
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Oct  5 22:35:31 2015 munoz david
** Last update Tue Feb 23 14:36:18 2016 David Munoz
*/

int	my_power_rec(int nb, int power)
{
  int	i;

  i = 1;
  if (nb == 0)
    return (0);
  if (power == 0)
    return (1);
  if (power > i)
    {
      return (nb * my_power_rec(nb, power - 1));
    }
  return (0);
}
