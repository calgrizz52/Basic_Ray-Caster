/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:42:00 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 21:21:18 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*cdst;
	const char	*csrc;
	int			n;
	int			len;

	cdst = dst;
	csrc = src;
	n = size;
	while (*cdst && n--)
		cdst++;
	len = cdst - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(src));
	while (*src)
	{
		if (n - 1 > 0)
			*cdst++ = *src;
		src++;
		n--;
	}
	*cdst = '\0';
	return (len + (src - csrc));
}
