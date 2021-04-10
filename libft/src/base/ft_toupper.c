/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:56:49 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 09:56:50 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ctype.h>

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}