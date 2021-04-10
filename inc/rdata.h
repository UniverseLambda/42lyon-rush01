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

typedef struct	s_square
{
	size_t		start_x;
	size_t		start_y;
	size_t		size;
}				t_square;

typedef struct	s_rdata
{
	size_t		size;		// Size of map
	char		filler;		// Character used to print the camp
	uint8_t		*map;		// Levels of the map (height)
	uint16_t	*values;	// Potential square size for each cases

	t_square	max_square;	// During research, the biggest square currently found
}				t_rdata;

#endif // RDATA_H