/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:26:06 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/09 15:30:39 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_and_create(int fd, t_list **lst)
{
	char	*buffer;
	int		bytes_read;

	while (!check_for_newline(*lst))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (clear_nodes(lst));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
			return (free(buffer));
		buffer[bytes_read] = '\0';
		if (!add_node(lst, buffer))
			return ;
	}
}

void	get_line_from_list(t_list **lst, char **line)
{
	int		len;
	t_list	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	aux = *lst;
	len = length_until_newline(*lst);
	if (!len)
		return ;
	*line = malloc(sizeof(char) * (len + 1));
	if (!*line)
		return (clear_nodes(lst));
	while (aux)
	{
		while (*((*aux).content + j) && i < len)
			*(*line + i++) = *((*aux).content + j++);
		j = 0;
		aux = (*aux).next;
	}
	*(*line + i) = '\0';
}

void	extract_remainder(t_list **lst)
{
	t_list	*last;
	char	*content;
	int		before;
	int		i;
	int		len;

	last = last_node(*lst);
	len = 0;
	before = length_until_newline(last);
	while (*((*last).content + before + len))
		len++;
	if (!len)
		return (clear_nodes(lst));
	content = malloc(sizeof(char) * (len + 1));
	if (!content)
		return (clear_nodes(lst));
	i = 0;
	while (*((*last).content + before) && i < len)
		*(content + i++) = *((*last).content + before++);
	*(content + i) = '\0';
	clear_nodes(lst);
	if (!add_node(lst, content))
		return ;
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;

	line = NULL;
	if (read(fd, line, 0) < 0)
	{
		clear_nodes(&lst);
		return (NULL);
	}
	else if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_and_create(fd, &lst);
	if (!lst)
		return (NULL);
	get_line_from_list(&lst, &line);
	if (!lst)
		return (NULL);
	extract_remainder(&lst);
	return (line);
}

