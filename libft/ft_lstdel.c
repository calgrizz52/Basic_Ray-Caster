/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 22:27:18 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 21:56:44 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (del)(void *, size_t))
{
	t_list *next;
	t_list *current;

	if (!alst || !*alst)
		return ;
	current = *alst;
	while (current)
	{
		next = (*current).next;
		del((*current).content, (*current).content_size);
		free(current);
		current = next;
	}
	*alst = NULL;
}
