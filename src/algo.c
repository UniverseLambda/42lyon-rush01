#include <stdio.h>
#include <unistd.h>

#include "../inc/rdata.h"

int	check_square(t_rdata *rush, size_t index)
{
	size_t	ring;

	ring = 1;
	while (ring < rush->values[index])
	{
		if (!check_ring(rush, index, ring))
			break ;
		++ring;
	}
	if (rush->max_square.size < (ring + 1))
	{
		rush->max_square.pos = index;
		rush->max_square.size = ring;
		return (1);
	}
	return (0);
}

void	print_camp(t_rdata *rush)
{
	size_t	x;
	size_t	y;
	size_t	start_x;
	size_t	start_y;

	start_x = rush->max_square.pos % rush->size;
	start_y = rush->max_square.pos / rush->size;
	y = start_y;
	while (y < (start_y + rush->max_square.size))
	{
		x = start_x;
		while (x < (start_x + rush->max_square.size))
		{
			rush->map[(y * rush->size) + x] = rush->filler;
			++x;
		}
		++y;
	}
	y = 0;
	while (y < rush->size)
	{
		write(STDOUT_FILENO, rush->map + (y * rush->size), rush->size);
		write(STDOUT_FILENO, "\n", 1);
		++y;
	}
}

void	find_square(t_rdata *rush)
{
	size_t	index;
	size_t	current_value;

	current_value = rush->biggest_value;
	while (current_value > 0 && rush->max_square.size < current_value)
	{
		index = 0;
		while (index < rush->size)
		{
			if (rush->values[index] == current_value)
				if (check_square(rush, index))
					if (rush->max_square.size == current_value)
						return ;
			++index;
		}
		--current_value;
	}
}

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
				|| rush->map[j] != rush->map[i] || rush->map[k] != rush->map[i])
				break ;
		}
		rush->values[i] = j - i;
		if (rush->values[i] > rush->biggest_value)
			rush->biggest_value = rush->values[i];
		++i;
	}
	find_square(rush);
	print_camp(rush);
}
