/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:26:23 by sguzman           #+#    #+#             */
/*   Updated: 2023/10/31 16:38:26 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstadd(t_list **lst, char *content)
{
	t_list	*last;
	t_list	*newlst;

	newlst = malloc(sizeof(t_list));
	if (!newlst)
		return (NULL);
	(*newlst).content = content;
	(*newlst).next = NULL;
	if (!*lst)
		*lst = newlst;
	else
	{
		last = ft_lstlast(*lst);
		(*last).next = newlst;
	}
	return (*lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux;

	if (!lst)
		return (NULL);
	aux = lst;
	while ((*aux).next)
		aux = (*aux).next;
	return (aux);
}
