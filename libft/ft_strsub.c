/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 09:23:48 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 21:46:45 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	int		count;

	count = 0;
	s2 = NULL;
	if (s == NULL)
		return (s2);
	if (start > 0)
	{
		while (start-- > 0)
			s++;
	}
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (s2);
	while (*s && len > 0)
	{
		*s2++ = *s++;
		count++;
		len--;
	}
	*s2 = '\0';
	return (s2 - count);
}
