/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 09:07:08 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 21:56:24 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	char			*cs;
	unsigned int	count;

	count = 0;
	cs = (char *)s;
	if (s == NULL)
		return (cs);
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (s2 == NULL)
		return (s2);
	while (*cs)
	{
		*s2++ = f(count, *cs++);
		count++;
	}
	*s2 = '\0';
	return (s2 - count);
}
