/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:26:06 by sguzman           #+#    #+#             */
/*   Updated: 2023/10/31 17:51:50 by sguzman          ###   ########.fr       */
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
	char	*buffer;
	int		bytes_read;

	while (!line_found(*lst))
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
		ft_lstadd(lst, buffer);
	}
}

int	lstsize(t_list *lst)
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

void	get_line(t_list *lst, char **line)
{
	int		len;
	t_list	*aux;
	int		i;
	int		j;

	aux = lst;
	len = lstsize(lst);
	*line = malloc(sizeof(char) * (len + 1));
	if (!*line)
		return ;
	while (aux && i < len)
	{
		while (*((*aux).content + j))
			**(line + i++) = *((*aux).content + j++);
		j = 0;
		aux = (*aux).next;
	}
	**(line + i++) = '\0';
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*line;

	lst = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	// PASO 1: leer y crear la lista y agregar cada lectura el buffer al final de la lst
	read_and_append(fd, &lst);
	// PASO 2: recorrer lst y crear line hasta el \n
	/*
	while (lst)
	{
		printf("%s\n", (*lst).content);
		lst = (*lst).next;
	}
	*/
	get_line(lst, &line);
	// PASO 3: liberar lst hasta \n y me quedo con el cachito
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = open(*(argv + argc - 1), O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
