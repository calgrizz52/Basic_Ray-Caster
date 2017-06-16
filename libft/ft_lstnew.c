/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:48:20 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 21:47:54 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	(*newlist).content = (void *)malloc(content_size);
	if (!(*newlist).content)
		return (NULL);
	if (content == 0)
	{
		(*newlist).content = NULL;
		(*newlist).content_size = 0;
	}
	else
	{
		ft_memcpy((*newlist).content, content, content_size);
		(*newlist).content_size = content_size;
	}
	(*newlist).next = NULL;
	return (newlist);
}
