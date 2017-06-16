/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:04:46 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 21:15:42 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *cs;
	char cc;
	char *new;

	new = NULL;
	cc = (char)c;
	cs = (char *)s;
	while (*cs)
	{
		if (*cs == cc)
			new = cs;
		cs++;
	}
	if (c == '\0')
		return (cs);
	return (new);
}
