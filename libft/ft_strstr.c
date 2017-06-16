/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:03:23 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 21:29:52 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t		count;

	count = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (!ft_strcmp(big, little))
		return (char *)(big);
	while (*big)
	{
		while ((*little == *big) && *little && *big)
		{
			big++;
			little++;
			count++;
			if (count == ft_strlen(little - count))
				return ((char *)(big - count));
		}
		little = little - count;
		big = (big - count) + 1;
		count = 0;
	}
	return (NULL);
}
