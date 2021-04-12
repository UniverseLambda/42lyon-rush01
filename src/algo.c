/*
**
**/

#include "../inc/rdata.h"
#include <stdio.h>

void	start(t_rdata *rush)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (i < (rush->size * rush->size))
	{
		j = i;
		k = i;
		while (1)
		{
			j += 1;
			k += rush->size;
			if (j % rush->size == 0
				|| k >= (rush->size * rush->size)
				|| rush->map[j] != rush->map[i]
				|| rush->map[k] != rush->map[i])
				break ;
		}
		rush->values[i] = j - i;
		++i;
	}
}
