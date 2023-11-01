/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:26:06 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/01 18:35:31 by sguzman          ###   ########.fr       */
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
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return ;
		}
		add_node(lst, buffer);
	}
}

void	get_line(t_list *lst, char **line)
{
	int		len;
	t_list	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	aux = lst;
	len = length_until_newline(lst);
	*line = malloc(sizeof(char) * (len + 1));
	if (!*line)
		return ;
	while (aux)
	{
		while (*((*aux).content + j) && i < len)
			*(*line + i++) = *((*aux).content + j++);
		j = 0;
		aux = (*aux).next;
	}
}

void	clear_until_last_node(t_list *lst)
{
	t_list	*tmp;

	while ((*lst).next)
	{
		tmp = (*lst).next;
		free((*lst).content);
		free(lst);
		lst = tmp;
	}
}

void	extract_remainder(t_list **lst)
{
	char	*content;
	int		before;
	int		i;
	int		len;
	t_list	*tmp;

	clear_until_last_node(*lst);
	len = 0;
	before = length_until_newline(*lst);
	while (*((**lst).content + before + len))
		len++;
	content = malloc(sizeof(char) * (len + 1));
	if (!content)
		return ;
	i = 0;
	while (*((**lst).content + before) && i < len)
		*(content + i++) = *((**lst).content + before++);
	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return ;
	(*tmp).content = content;
	(*tmp).next = NULL;
	free(*lst);
	*lst = tmp;
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	read_and_create(fd, &lst);
	if (!lst)
		return (NULL);
	get_line(lst, &line);
	if (!line)
		return (NULL);
	extract_remainder(&lst);
	return (line);
}

/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(*(argv + argc - 1), O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
*/
