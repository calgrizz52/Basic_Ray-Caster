/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:07:46 by mkok              #+#    #+#             */
/*   Updated: 2016/12/11 20:49:29 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**newstr;
	int		wordcount;
	int		wordperm;
	int		strlen;

	if (!s)
		return (NULL);
	strlen = 0;
	wordcount = ft_wordcounter(s, c);
	wordperm = wordcount;
	newstr = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!newstr)
		return (newstr);
	while (wordcount--)
	{
		while (*s == c && *s)
			s++;
		*newstr++ = ft_strsub(s, 0, ft_strdlen(s, c));
		s = s + ft_strdlen(s, c);
	}
	*newstr = 0;
	return (newstr - wordperm);
}
