/*
** my_strcmp.c for my_strcmp in /home/munoz_d/rendu/Piscine_C_J07/lib/my
** 
** Made by munoz david
** Login   <munoz_d@epitech.net>
** 
** Started on  Tue Oct  6 10:59:26 2015 munoz david
** Last update Thu Oct 22 14:20:26 2015 munoz david
*/

int	my_strcmp(char *s1, char *s2)
{
  int	compt;
  int	retur;

  compt = 0;
  while (s1[compt] == s2[compt] && s1[compt] != '\0' && s2[compt] != '\0')
    {
      compt = compt + 1;
    }
  retur = s1[compt] - s2[compt];
  return (retur);
}
