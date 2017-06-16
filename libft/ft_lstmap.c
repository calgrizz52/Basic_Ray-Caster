/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkok <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:44:10 by mkok              #+#    #+#             */
/*   Updated: 2016/12/09 21:29:04 by mkok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*next;
	t_list	*newnode;
	t_list	*newcurrent;
	t_list	*prv;

	if (!lst || !f)
		return (NULL);
	next = (*lst).next;
	newnode = (t_list *)malloc(sizeof(t_list));
	if (newnode)
	{
		newnode = f(lst);
		lst = next;
		prv = newnode;
		while (lst)
		{
			newcurrent = (t_list *)malloc(sizeof(t_list));
			newcurrent = f(lst);
			(*prv).next = newcurrent;
			prv = newcurrent;
			lst = (*lst).next;
		}
	}
	return (newnode);
}
