/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:10:13 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 21:31:47 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *cs;

	cs = (unsigned char *)s;
	while (n > 0)
	{
		if (*cs == (unsigned char)c)
			return (cs);
		cs++;
		n--;
	}
	return (NULL);
}
