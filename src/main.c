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
	ssize_t		rdcount;

	rdcount = read(STDIN_FILENO, buffer, 1024);
	buffer[rdcount] = '\0';
	data->size = ft_atoi(buffer);
	data->map = malloc(data->size * data->size);
	if (data->map == NULL)
		return (0);
	data->values = malloc(data->size * data->size);
	if (data->map == NULL)
	{
		free(data->map);
		return (0);
	}
	read(STDIN_FILENO, buffer, 2);
	data->filler = buffer[0];
	i = 0;
	while (i < data->size)
	{
		read(STDIN_FILENO,
			&data->map[i * data->size], data->size + (i != (data->size - 1)));
		++i;
	}
	return (1);
}

void	conv_map(t_rdata *data)
{
	size_t	i;

	i  = 0;
	while (i < (data->size * data->size))
	{
		data->map[i] -= '0';
		i++;
	}
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
	conv_map(&data);
	data.max_square.size = 0;
	data.max_square.start_x = 0;
	data.max_square.start_y = 0;
	return (0);
}
