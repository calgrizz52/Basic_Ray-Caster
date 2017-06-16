/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 10:03:39 by mkok              #+#    #+#             */
/*   Updated: 2016/12/10 21:56:05 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int			ws_front;
	int			ws_back;
	int			strlen;
	char		*str;
	const char	*head;

	head = s;
	ws_front = 0;
	ws_back = 0;
	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	while ((*s == '\t' || *s == '\n' || *s == ' ') && *s++)
		ws_front++;
	s = head + (strlen - 1);
	while ((*s == '\t' || *s == '\n' || *s == ' ') && *s--)
		ws_back++;
	s = head + ws_front;
	if (ws_front == ws_back && ft_allws(s - ws_front))
		str = ft_strsub(s, 0, (strlen - (ws_front - ws_back)));
	else
		str = ft_strsub(s, 0, (strlen - ws_front - ws_back));
	return (str);
}
