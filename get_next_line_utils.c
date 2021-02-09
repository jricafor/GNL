/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jricafor <jricafor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:44:57 by jricafor          #+#    #+#             */
/*   Updated: 2020/10/01 11:54:47 by jricafor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*join_line(char *tmp, char *sample, char *buff)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (sample[i])
	{
		tmp[i] = sample[i];
		i++;
	}
	while (buff[y] && buff[y] != '\n')
	{
		tmp[i] = buff[y];
		i++;
		y++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*append_line(char *sample, char *buff, int size)
{
	char *tmp;
	tmp = malloc(sizeof(char) * (ft_strlen(buff) + size + 1));
	tmp = join_line(tmp, sample, buff);
	return (tmp);
}

int		read_buff(int fd, char *buff, char **line)
{
	int	byte_read;
	int i;
	int size;

	size = ft_strlen(*line);
	i = 0;
	while (buff[i])
		buff[i++] = '\0';
	while ((byte_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		i = 0;
		buff[byte_read] = '\0';
		*line = append_line(*line, buff, size);
		while (buff[i] && buff[i] != '\n')
			i++;
		size += i;
		if (buff[i] == '\n')
			return (1);
	}
	if (byte_read < 0)
		return (-1);
	return (0);
}

int		set_line(char **line, int fd, char *buff, int i)
{
	int	y;
	char *tmp;

	y = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	buff[i] = '0';
	i++;
	if (buff[i] != '\0')
	{
		while (buff[i] && buff[i] != '\n')
		{
			tmp[y] = buff[i];
			y++;
			i++;
		}
		tmp[y] = '\0';
		*line = append_line(*line, tmp, 0);
	}
	free(tmp);
	if (buff[i] != '\n')
		return (read_buff(fd, buff, line));
	return (1);
}