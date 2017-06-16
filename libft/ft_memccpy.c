/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:49:08 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 21:30:37 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *csrc;
	unsigned char *cdst;

	csrc = (unsigned char*)src;
	cdst = (unsigned char*)dst;
	while (n > 0)
	{
		if (*csrc == (unsigned char)c)
		{
			*cdst = *csrc;
			return (cdst + 1);
		}
		else
			*cdst = *csrc;
		csrc++;
		cdst++;
		n--;
	}
	return (0);
}
