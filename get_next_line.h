/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jricafor <jricafor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:40:21 by jricafor          #+#    #+#             */
/*   Updated: 2020/10/01 11:43:23 by jricafor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *str);
char	*join_line(char *tmp, char *sample, char *buff);
char	*append_line(char *sample, char *buff, int size);
int		read_buff(int fd, char *buff, char **line);
int		set_line(char **line, int fd, char *buff, int i);

#endif
