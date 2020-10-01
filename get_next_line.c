/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jricafor <jricafor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:39:08 by jricafor          #+#    #+#             */
/*   Updated: 2020/10/01 11:55:14 by jricafor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static	int	i = 0;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	i = find_new_line(buf, line, i);
	return (0);
}
