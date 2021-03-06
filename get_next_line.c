/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jricafor <jricafor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:39:08 by jricafor          #+#    #+#             */
/*   Updated: 2021/02/09 20:47:14 by jricafor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char			buff[BUFFER_SIZE];
	int					i;
	int					ret;

	if (!fd || fd < 1 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = "";
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		ret = set_line(line, fd, buff, i);
	else
		ret = read_buff(fd, buff, line);
	return (ret);
}
