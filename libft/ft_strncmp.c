/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:45:41 by mkok              #+#    #+#             */
/*   Updated: 2016/12/10 23:06:30 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *cs1;
	unsigned char *cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (*cs1 && *cs2 && n)
	{
		if (*cs1 != *cs2)
			return (*cs1 - *cs2);
		cs1++;
		cs2++;
		n--;
	}
	if (n)
		return (*cs1 - *cs2);
	return (0);
}
