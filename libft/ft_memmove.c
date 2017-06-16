/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:31:20 by mkok              #+#    #+#             */
/*   Updated: 2016/12/02 22:43:21 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *temp;

	temp = (unsigned char *)malloc(sizeof(unsigned char) * len + 1);
	if (temp)
	{
		ft_memcpy(temp, src, len);
		ft_memcpy(dst, temp, len);
	}
	free(temp);
	return (dst);
}
