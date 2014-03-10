/*
** show_alloc_mem.c for show_alloc_mem in /home/thibauj/rendu/Git_perso/PSU2013_malloc
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Mon Mar 10 18:17:50 2014 thibau_j
** Last update Mon Mar 10 18:17:52 2014 thibau_j
*/

#include <stdio.h>
#include "malloc.h"

void		show_alloc_mem()
{
  t_block	*tmp;

  tmp = g_block;
  printf("break : %p\n", sbrk(0));
  while (tmp != NULL)
    {
      if (tmp->free == FALSE)
	printf("%p - %p : %zu octets\n", tmp, tmp + tmp->size, tmp->size);
      tmp = tmp->next;
    }
}
