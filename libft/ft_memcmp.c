/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:50:34 by mkok              #+#    #+#             */
/*   Updated: 2016/12/02 17:40:38 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *cs1;
	unsigned char *cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (n != 0)
	{
		if (*cs1 != *cs2)
			return (*cs1 - *cs2);
		cs1++;
		cs2++;
		n--;
	}
	return (0);
}
