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

<<<<<<< HEAD
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
=======
int		looping(char *sample)
{
	int z;

	if(!sample || sample == NULL)
		return (1);
	z = 0;
	while (sample[z] != '\n' && sample[z])
		z++;
	if (sample[z] == '\n')
		return (0);
	return (1);
}

char	*flegma(char *src, int start, int end)
{
	char *dest;
	int i;

	i = 0;
	dest = malloc(sizeof(char) * (end - start + 1));
	if (!dest)
		return (NULL);
	while (start < end && src[start])
	{
		dest[i] = src[start];
		i++;
		start++;
>>>>>>> 38c63828596e73ce071a79bd94a617ee13e09075
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*append_line(char *sample, char *buff, int size)
{
<<<<<<< HEAD
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
	{
		buff[i] = '\0';
		i++;
	}
	while ((byte_read = read(fd, buff, BUFFER_SIZE)) > 0)
=======
	char	*res;
	int		i;
	int		y;
	
	if (!(res = malloc(sizeof(char) * (ft_strlen(sample) + BUFFER_SIZE + 1))))
		return (NULL);
	i = 0;
	y = 0;
	if (sample)
	{
		while (sample[i])
		{
			res[y] = sample[i];
			i++;
			y++;
		}
		i = 0;
	}
	while (buf[i])
>>>>>>> 38c63828596e73ce071a79bd94a617ee13e09075
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

<<<<<<< HEAD
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
	if (buff[i] != '\n')
		return (read_buff(fd, buff, line));
=======
int		set_line(char *sample, char **line, char **tmp)
{
	int		size;

	*line = flegma("", 0, 1);
	if (sample == NULL)
		return (0);
	size = 0;
	if (sample[size] == '\n')
	{
		*tmp = flegma(sample, size + 1, ft_strlen(sample));
		return (1);
	}
	while (sample[size] != '\n' && sample[size] != '\0')
	size++;
	*line = flegma(sample, 0, size);
	if (sample[size] == '\n')
		size++;
	if (sample[size] == '\0')
	{
		*tmp = NULL;
		return (0);
	}
	*tmp = flegma(sample, size, ft_strlen(sample));
>>>>>>> 38c63828596e73ce071a79bd94a617ee13e09075
	return (1);
}