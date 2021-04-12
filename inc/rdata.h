/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdata.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:45:12 by clsaad            #+#    #+#             */
/*   Updated: 2021/04/10 15:45:13 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RDATA_H
# define RDATA_H

# include <stdint.h>
# include <stddef.h>

typedef struct s_square
{
	size_t		pos;
	size_t		size;
}				t_square;

typedef struct s_rdata
{
	size_t		size;
	char		filler;
	uint8_t		*map;
	uint16_t	*values;

	uint16_t	biggest_value;
	t_square	max_square;
}				t_rdata;

void			start(t_rdata *rush);
int				check_ring(t_rdata *rush, size_t index, size_t ring_size);

#endif // RDATA_H
