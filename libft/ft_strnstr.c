/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:03:23 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 21:40:13 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		count;

	count = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (!ft_strcmp(big, little))
		return (char *)(big);
	while (*big && len)
	{
		while ((*little == *big) && *little && *big && len)
		{
			big++;
			little++;
			count++;
			len--;
			if (count == ft_strlen(little - count))
				return ((char *)(big - count));
		}
		len = len + count - 1;
		little = little - count;
		big = (big - count) + 1;
		count = 0;
	}
	return (NULL);
}
