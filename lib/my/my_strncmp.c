/*
** my_strncmp.c for strncmp in /home/munoz_d/rendu/Piscine_C_J07/lib/my
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Oct  6 11:37:37 2015 munoz david
** Last update Thu Mar 31 01:03:47 2016 David Munoz
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	compt;
  int	cmp;

  compt = 0;
  while (s1[compt] == s2[compt])
    {
      compt = compt + 1;
    }
  if (n - 1 >= compt)
    cmp = s1[compt] - s2[compt];
  else
    return (0);
  return (cmp);
}
