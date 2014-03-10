/*
** calloc.c for calloc.c in /home/thibauj/rendu/Git_perso/PSU2013_malloc
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Mon Mar 10 18:17:00 2014 thibau_j
** Last update Mon Mar 10 18:17:03 2014 thibau_j
*/

#include <stdlib.h>
#include <string.h>

void*	calloc(size_t nmemb, size_t size)
{
  void	*new;
  int	s;

  s = nmemb * size;
  new = malloc(s);
  if (new)
    memset(new, 0, s);
  return (new);
}
