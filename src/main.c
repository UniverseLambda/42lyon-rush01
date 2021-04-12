/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:07:33 by clsaad            #+#    #+#             */
/*   Updated: 2021/04/10 15:07:34 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rdata.h"

#include <ft_stdlib.h>
#include <ft_string.h>

#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>
int	read_data(t_rdata *data)
{
	char		buffer[1024];
	size_t		i;

	i = 0;
	while (1)
		if (read(STDIN_FILENO, buffer + i, 1) != 1 || buffer[i++] == '\n')
			break ;
	buffer[i] = '\0';
	data->size = ft_atoi(buffer);
	data->map = ft_calloc(data->size * data->size, sizeof(*(data->map)));
	if (data->map == NULL)
		return (0);
	data->values = ft_calloc(data->size * data->size, sizeof(*(data->values)));
	if (data->map == NULL)
	{
		free(data->map);
		return (0);
	}
	read(STDIN_FILENO, buffer, 2);
	data->filler = buffer[0];
	i = -1;
	while (++i < data->size)
		read(STDIN_FILENO, &data->map[i * data->size],
			(data->size + (i != (data->size - 1))));
	return (1);
}

int	main(int argc, char **argv)
{
	t_rdata	data;

	(void)argc;
	(void)argv;
	if (!read_data(&data))
	{
		write(STDERR_FILENO, "internal error\n", 15);
		return (1);
	}
	data.max_square.size = 0;
	data.biggest_value = 0;
	data.max_square.pos = 0;
	start(&data);
	return (0);
}
