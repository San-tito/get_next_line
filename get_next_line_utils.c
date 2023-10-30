/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:26:23 by sguzman           #+#    #+#             */
/*   Updated: 2023/10/30 19:29:28 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstadd(t_list **lst, char *content, int len)
{
	t_list	*last;
	t_list	*newlst;
	int		i;

	newlst = malloc(sizeof(t_list));
	if (!newlst)
		return (NULL);
	(*newlst).content = malloc(sizeof(char) * (len + 1));
	(*newlst).next = NULL;
	i = 0;
	while (*(content + i) && i < len)
	{
		*((*newlst).content + i) = *(content + i);
		i++;
	}
	*((*newlst).content + i) = '\0';
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
