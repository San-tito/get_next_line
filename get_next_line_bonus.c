/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:07:49 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/09 15:33:54 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static t_list	*lst[OPEN_MAX + 1];
	char			*line;

	line = NULL;
	if (read(fd, line, 0) < 0)
	{
		clear_nodes(lst + fd);
		return (NULL);
	}
	else if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	read_and_create(fd, lst + fd);
	if (!lst[fd])
		return (NULL);
	get_line_from_list(lst + fd, &line);
	if (!lst[fd])
		return (NULL);
	extract_remainder(lst + fd);
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
		printf("%s",line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

*/
