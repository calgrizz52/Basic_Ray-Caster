/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 13:05:17 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 21:53:50 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	int		sign;

	sign = n;
	i = 0;
	len = ft_icount(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (str);
	if (n == 0)
		str[i++] = '0';
	while (n != 0)
	{
		str[i++] = ft_abs(n % 10) + '0';
		n = n / 10;
	}
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str, i);
	return (str);
}
