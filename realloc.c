/*
** realloc.c for realloc in /home/thibauj/rendu/Git_perso/PSU2013_malloc
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Mon Mar 10 18:16:27 2014 thibau_j
** Last update Mon Mar 10 18:16:28 2014 thibau_j
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void		*realloc(void *ptr, size_t size)
{
  void		*nptr;

  if (ptr == NULL)
    return (malloc(size));
  if ((nptr = malloc(size)) == NULL)
    return (NULL);
  size = size / 2;
  size += 47;
  memcpy(nptr, ptr, size);
  free(ptr);
  return (nptr);
}
