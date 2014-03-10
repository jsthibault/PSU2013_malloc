/*
** malloc.h for malloc.h in /home/thibau_j/tpMalloc
**
** Made by Jean-Stéphane THIBAULT
** Login   <thibau_j@epitech.net>
**
** Started on  Sat Feb  8 15:23:33 2014 Jean-Stéphane THIBAULT
** Last update Mon Mar 10 18:18:02 2014 thibau_j
*/

#ifndef			MY_MALLOC_H_
# define		MY_MALLOC_H_

# include		<unistd.h>
# define		FALSE 0
# define		TRUE  1
# define		BLOCK_SIZE sizeof(struct s_block)

typedef struct		s_block
{
  size_t		size;
  char			free;
  struct s_block	*prev;
  struct s_block	*next;
  void			*tmp;
  char			data[1];
}			t_block;

static void		*g_block = NULL;

#endif /* !MY_MALLOC_H_ */
