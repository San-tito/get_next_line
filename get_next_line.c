/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:26:06 by sguzman           #+#    #+#             */
/*   Updated: 2023/10/30 19:29:45 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_found(t_list *lst)
{
	t_list	*last;
	int		i;

	if (!lst)
		return (0);
	last = ft_lstlast(lst);
	i = 0;
	while (*((*last).content + i))
	{
		if (*((*last).content + i) == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	read_and_append(int fd, t_list **lst)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (!line_found(*lst) && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);	
		ft_lstadd(lst, buffer, bytes_read);
	}
}
char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;

	line = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	// PASO 1: leer y crear la lista y agregar cada lectura el buffer al final de la lst
	read_and_append(fd, &lst);

	while(lst)
	{
		printf("%s",(*lst).content);
		lst = (*lst).next;
	}
	// PASO 2: recorrer lst y crear line hasta el \n
	// PASO 3: liberar lst hasta \n y me quedo con el cachito
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = open(*(argv + argc - 1), O_RDONLY);
	printf("get_next_line -> %s", get_next_line(fd));
	close(fd);
	return (0);
}
