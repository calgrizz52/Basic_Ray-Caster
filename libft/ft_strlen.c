/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:43:56 by mkok              #+#    #+#             */
/*   Updated: 2017/03/11 14:42:53 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	int				count;
	const char		*cstr;

	cstr = str;
	count = 0;
	while (*cstr)
	{
		count++;
		cstr++;
	}
	return (count);
}
