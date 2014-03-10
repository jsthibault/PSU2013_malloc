/*
** free.c for free in /home/thibauj/rendu/Git_perso/PSU2013_malloc
**
** Made by thibau_j
** Login   <thibau_j@epitech.net>
**
** Started on  Mon Mar 10 18:19:09 2014 thibau_j
** Last update Mon Mar 10 18:19:10 2014 thibau_j
*/

#include "malloc.h"
#include <stdio.h>

static void    		fusionBlock(t_block **ptrSend)
{
  t_block		*ptr;

  ptr = *ptrSend;
  if (ptr->next != NULL && ptr->next->free == TRUE)
    {
      ptr->size = ptr->size + BLOCK_SIZE + ptr->next->size;
      ptr->next = ptr->next->next;
      if (ptr->next != NULL)
  	ptr->next->prev = ptr;
    }
}

static int		checkAdress(void *ptr)
{
  char                  *tmpCastChar;
  void                  *tmpCastVoid;
  t_block		*tmp;
  void			*lastBreack;

  lastBreack = sbrk(0);
  tmpCastChar = ptr;
  tmpCastChar -= BLOCK_SIZE;
  tmpCastVoid = tmpCastChar;
  tmp = tmpCastVoid;
  if (g_block == NULL)
    return (-1);
  if (ptr == NULL)
    return (-1);
  if (ptr > g_block && ptr < lastBreack)
    {
      if (ptr == tmp->tmp)
	return (1);
    }
  return (-1);
}

void			free(void *ptr)
{
  t_block		*block;
  char			*tmpCastChar;
  void			*tmpCastVoid;

  if (checkAdress(ptr) != -1)
    {
      tmpCastChar = ptr;
      tmpCastChar -= BLOCK_SIZE;
      tmpCastVoid = tmpCastChar;
      block = tmpCastVoid;
      block->free = TRUE;
      if (block->prev && block->prev->free == TRUE)
	fusionBlock(&(block->prev));
      if (block->next)
	fusionBlock(&block);
      else
	{
	  if (block->prev)
	    block->prev->next = NULL;
	  else
	    g_block = NULL;
	}
    }
}
