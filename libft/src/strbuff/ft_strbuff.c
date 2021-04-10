/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:39:48 by clsaad            #+#    #+#             */
/*   Updated: 2020/12/08 12:39:49 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include <ft_strbuff.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

typedef struct s_bblock
{
	struct s_bblock	*next;
	char			data[BUFFER_SIZE];
}					t_bblock;

typedef struct s_buff
{
	size_t			content_size;
	size_t			buff_size;
	t_bblock		block;
}					t_buff;

t_buff	*create_buffer(void)
{
	t_buff	*buff;

	buff = malloc(sizeof(t_buff));
	if (buff != NULL)
	{
		buff->content_size = 0;
		buff->buff_size = BUFFER_SIZE;
		buff->block.next = NULL;
	}
	return (buff);
}

static t_bblock	*get_or_extend_buffer(t_buff *buff, size_t index)
{
	t_bblock	*previous;
	size_t		i;

	i = 0;
	previous = &(buff->block);
	while (previous->next != NULL && i < index)
	{
		previous = previous->next;
		++i;
	}
	if (i == index)
		return (previous);
	previous->next = malloc(sizeof(t_bblock));
	if (previous->next == NULL)
		return (NULL);
	previous->next->next = NULL;
	return (previous->next);
}

int	write_char_buffer(t_buff *buff, char c)
{
	const int	index = buff->content_size / buff->buff_size;
	t_bblock	*elem;

	elem = get_or_extend_buffer(buff, index);
	if (elem == NULL)
		return (0);
	((char *)elem->data)[buff->content_size % buff->buff_size] = c;
	buff->content_size++;
	return (1);
}

char	*merge_buffer(t_buff *buff)
{
	char		*merged;
	size_t		index;
	t_bblock	*block;
	size_t		last_block;

	if (!write_char_buffer(buff, 0))
		return (NULL);
	merged = malloc(buff->content_size + 1);
	if (merged == NULL)
		return (NULL);
	block = &(buff->block);
	last_block = 0;
	index = 0;
	while (index < buff->content_size)
	{
		if (index / buff->buff_size != last_block)
		{
			block = block->next;
			++last_block;
		}
		merged[index] = ((char *)block->data)[index % buff->buff_size];
		++index;
	}
	merged[index] = 0;
	return (merged);
}

void	destroy_buffer(t_buff *buff)
{
	t_bblock	*next_block;
	t_bblock	*tmp;

	next_block = buff->block.next;
	while (next_block != NULL)
	{
		tmp = next_block;
		next_block = next_block->next;
		free(tmp);
	}
	free(buff);
}
