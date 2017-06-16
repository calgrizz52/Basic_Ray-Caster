/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:22:21 by mkok              #+#    #+#             */
/*   Updated: 2016/12/11 18:33:19 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *csrc;
	char *cdst;

	csrc = (char *)src;
	cdst = (char *)dst;
	while (n > 0)
	{
		*cdst = *csrc;
		csrc++;
		cdst++;
		n--;
	}
	return (dst);
	free(csrc);
	free(cdst);
}
