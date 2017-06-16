/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:53:43 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 21:57:00 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *cs;

	cs = (char *)s;
	while (*cs)
	{
		if (*cs == (char)c)
			return (cs);
		cs++;
	}
	if (*cs == (char)c)
		return (cs);
	else
		return (0);
}
