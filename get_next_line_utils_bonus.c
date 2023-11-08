/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:08:06 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/08 19:09:53 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_for_newline(t_list *lst)
{
	t_list	*last;
	int		i;

	if (!lst)
		return (0);
	last = last_node(lst);
	i = 0;
	while (*((*last).content + i))
	{
		if (*((*last).content + i++) == '\n')
			return (1);
	}
	return (0);
}

t_list	*last_node(t_list *lst)
{
	t_list	*aux;

	if (!lst)
		return (NULL);
	aux = lst;
	while ((*aux).next)
		aux = (*aux).next;
	return (aux);
}

t_list	*add_node(t_list **lst, char *content)
{
	t_list	*last;
	t_list	*newlst;

	newlst = malloc(sizeof(t_list));
	if (!newlst)
	{
		free(content);
		content = NULL;
		clear_nodes(lst);
		return (NULL);
	}
	(*newlst).content = content;
	(*newlst).next = NULL;
	if (!*lst)
		*lst = newlst;
	else
	{
		last = last_node(*lst);
		(*last).next = newlst;
	}
	return (*lst);
}

int	length_until_newline(t_list *lst)
{
	int		i;
	int		len;
	t_list	*aux;

	aux = lst;
	i = 0;
	len = 0;
	while (aux)
	{
		while (*((*aux).content + i))
		{
			len++;
			if (*((*aux).content + i++) == '\n')
				break ;
		}
		i = 0;
		aux = (*aux).next;
	}
	return (len);
}

void	clear_nodes(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (**lst).next;
		free((**lst).content);
		free(*lst);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}
