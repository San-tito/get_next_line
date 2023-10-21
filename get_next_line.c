/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santito </var/spool/mail/santito>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:11:26 by santito           #+#    #+#             */
/*   Updated: 2023/10/20 17:07:49 by santito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];

	if (fd < 0 || read(fd, buf, BUFFER_SIZE) < 0)
		return (NULL);
	return (buf);
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = open(*(argv + argc - 1), O_RDONLY);
	printf("get_next_line -> %s", get_next_line(fd));
	close(fd);
	return (0);
}
