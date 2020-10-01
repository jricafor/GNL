/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jricafor <jricafor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:39:08 by jricafor          #+#    #+#             */
/*   Updated: 2020/07/20 12:40:12 by jricafor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *set_line(char *buf, int start, int i)
{
	char *str;
	int y;

	str = malloc(sizeof(char) * (i - start) + 1);
	y = 0;
	while (start != i)
		str[y++] = buf[start++];
	str[y] = '\0';
	return (str);
}

int	find_new_line(char *buf, char **line, int i)
{
	int start;

	start = i;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	*line = NULL;
	*line = malloc(sizeof(char) * (i - start) + 1);
	*line = set_line(buf, start, i);
	if (buf[i + 1] && buf[i] == '\n')
	 i++;
	return (i);
}

int gnl(int fd, char **line)
{
	int		ret;
	char	buf[BUFFER_SIZE + 1];
	static	int	i = 0;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);

	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	
	i = find_new_line(buf, line, i);

	return (0);
}