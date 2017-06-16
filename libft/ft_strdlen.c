/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:08:33 by mkok              #+#    #+#             */
/*   Updated: 2017/03/11 14:21:06 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strdlen(char const *str, char c)
{
	int				count;
	char const		*cstr;

	cstr = str;
	count = 0;
	while (*cstr && *cstr++ != c)
		count++;
	return (count);
}
