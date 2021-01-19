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

int get_next_line(int fd, char **line)
{
	int				bytes_read;
	char			buf[BUFFER_SIZE + 1];
	char			*sample;
	static char		*tmp = NULL;

	*line = NULL;
	sample = tmp;
	if (!fd || fd < 1 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	while (looping(sample) && (bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		if (sample != NULL)
			tmp = flegma(sample, 0, ft_strlen(sample) + ft_strlen(buf));	
		if (!(sample = malloc(sizeof(char) * (ft_strlen(sample) + BUFFER_SIZE + 1))))
			return (-1);
		sample = append_sample(tmp, buf);
		if (sample == NULL)
			return (-1);
	}
	set_line(sample, line, &tmp);
	if (bytes_read != 0)
		return (1);
	return (0);
}