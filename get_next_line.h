/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:26:16 by sguzman           #+#    #+#             */
/*   Updated: 2023/11/08 18:13:36 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				read_and_create(int fd, t_list **lst);
void				get_line_from_list(t_list **lst, char **line);
void				extract_remainder(t_list **lst);
int					check_for_newline(t_list *lst);
t_list				*last_node(t_list *lst);
t_list				*add_node(t_list **lst, char *content);
int					length_until_newline(t_list *lst);
void				clear_nodes(t_list **lst);

#endif
