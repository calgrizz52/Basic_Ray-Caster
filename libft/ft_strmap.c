/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:58:48 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 22:01:55 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	char	*cs;
	int		count;

	count = 0;
	cs = (char *)s;
	if (s == NULL)
		return (cs);
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (s2 == NULL)
		return (s2);
	while (*cs)
	{
		*s2++ = f(*cs++);
		count++;
	}
	*s2 = '\0';
	return (s2 - count);
}
