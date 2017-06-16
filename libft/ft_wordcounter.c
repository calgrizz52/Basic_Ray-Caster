/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:42:34 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 22:12:28 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcounter(const char *s, char c)
{
	unsigned int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (count);
}
