#include "../inc/rdata.h"

int	check_ring(t_rdata *rush, size_t index, size_t ring_size)
{
	size_t	x;
	size_t	y;
	size_t	start_x;
	size_t	start_y;
	uint8_t	level;

	level = rush->map[index];
	start_x = (index % rush->size);
	start_y = (index / rush->size);
	x = start_x + 1;
	y = start_y + ring_size;
	while (x - start_x <= ring_size)
	{
		if (rush->map[(y * rush->size) + x] != level)
			return (0);
		++x;
	}
	--x;
	while (--y > start_y)
	{
		if (rush->map[(y * rush->size) + x] != level)
			return (0);
	}
	return (1);
}
