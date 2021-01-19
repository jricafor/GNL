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

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

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
	}
	dest[i] = '\0';
	return (dest);
}

char	*append_sample(char *sample, char buf[BUFFER_SIZE + 1])
{
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
	{
		res[y] = buf[i];
		i++;
		y++;
	}
	res[y] = '\0';
	return (res);
}

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
	return (1);
}