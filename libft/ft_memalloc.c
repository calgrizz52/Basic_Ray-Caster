/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:19:47 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 21:52:31 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *space;

	space = malloc(sizeof(char) * size);
	if (space == NULL)
		return (NULL);
	ft_memset(space, 0, size);
	return (space);
}
