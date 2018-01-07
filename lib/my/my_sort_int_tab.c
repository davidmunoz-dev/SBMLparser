/*
** my_sort_int_tab.c for sort_int_tab in /home/munoz_d/rendu/Piscine_C_J07/lib/my
** 
** Made by munoz david
** Login   <munoz_d@epitech.net>
** 
** Started on  Tue Oct  6 11:19:27 2015 munoz david
** Last update Thu Oct 22 14:07:24 2015 munoz david
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	tmp;
  int	pos;
  int	count;
  int	tmpo;

  count = 0;
  pos = 0;
  while (pos != size - 1)
    {
      while (count != size - 1)
	{
	  if (count == pos)
	    tmp = pos;
	  if (tab[count] < tab[tmp])
	    tmp = count;
	  count = count + 1;
	}
      tmpo = tab[pos];
      tab[pos] = tab[tmp];
      tab[tmp] = tmpo;
      pos = pos + 1;
      count = pos;
    }
}
