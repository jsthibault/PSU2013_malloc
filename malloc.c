/*
** malloc.c for malloc in /home/thibau_j/tpMalloc
**
** Made by Jean-Stéphane THIBAULT
** Login   <thibau_j@epitech.net>
**
** Started on  Sat Feb  8 15:23:21 2014 Jean-Stéphane THIBAULT
** Last update Mon Mar 10 18:18:53 2014 thibau_j
*/

#include		<stdio.h>
#include		<unistd.h>
#include		<stdlib.h>

#include		"malloc.h"

static t_block		*makeMemBigger(t_block *ptr, size_t size)
{
  t_block		*newBlock;

  if ((newBlock = sbrk(0)) == (void *)-1)
    exit(EXIT_FAILURE);
  if (sbrk(BLOCK_SIZE + size) == (void *)-1)
    return (NULL);
  newBlock->prev = ptr;
  newBlock->next = NULL;
  newBlock->tmp = newBlock->data;
  newBlock->size = size;
  newBlock->free = FALSE;
  if (ptr != NULL)
    ptr->next = newBlock;
  return (newBlock);
}

/*
** La fonction au dessus ajoute un block avec la size donné
** en paramètre
*/
static void		splitBlock(t_block *ptr, size_t size)
{
  t_block		*new;

  new = (void *)ptr->data + size;
  new->free = TRUE;
  new->prev = ptr;
  new->tmp = new->data;
  new->next = ptr->next;
  if (ptr->next != NULL)
    ptr->next->prev = new;
  new->size = ptr->size - size - BLOCK_SIZE;
  ptr->size = size;
  ptr->next = new;
}

static t_block		*findAvailableBlock(t_block **ptr, size_t size)
{
  t_block		*tmp;

  tmp = g_block;
  while (tmp != NULL && !(tmp->free == TRUE && tmp->size >= size))
    {
      *ptr = tmp;
      tmp = tmp->next;
    }
  return (tmp);
}

static void		*mallocSecondBlock(t_block **newBase, t_block **ptr,
					   size_t size)
{
  *ptr = g_block;
  if (((*newBase) = findAvailableBlock(ptr, size)) == NULL)
    {
      if (((*newBase) = makeMemBigger(*ptr, size)) == NULL)
	return (NULL);
    }
  else
    {
      if (((*newBase)->size - size) >= (BLOCK_SIZE))
	splitBlock(*newBase, size);
      (*newBase)->free = FALSE;
    }
  return (*newBase);
}

void			*malloc(size_t size)
{
  t_block		*newBase;
  t_block		*ptr;

  if ((int)size <= 0)
    return (NULL);
  else if (g_block == NULL)
    {
      if ((newBase = makeMemBigger(NULL, size)) == NULL)
	return (NULL);
      g_block = newBase;
    }
  else
    {
      if (mallocSecondBlock(&newBase, &ptr, size) == NULL)
	return (NULL);
    }
  return (newBase->data);
}
