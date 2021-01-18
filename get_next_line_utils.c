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

/** cherche le next \n et return une size **/
int		n_isfound(char *sample)
{
	int size;
	int z;

	if(!sample || sample == NULL || !sample[0])
		return (-1);
	size = 0;
	z = 0;
	if (sample[z] == '\n' && sample[z + 1])
		z++;
	while (sample[z] != '\n' && sample[z])
	{
		z++;
		size++;
		if(sample[z] == '\0')
			return (0);
	}
	return (size);
}

char	*flegma(char *src, int offset)
{
	char *dest;
	int i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	while (src[offset] != '\0')
	{
		dest[i] = src[offset];
		i++;
		offset++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*append_sample(char *sample, char buf[BUFFER_SIZE + 1])
{
	char	*res;
	int		i;
	int		y;
	
	if (!sample)
		return (buf);
	res = malloc(sizeof(char) * (ft_strlen(sample) + BUFFER_SIZE + 1));
	if (!res)
		return (NULL);
	i = 0;
	y = 0;
	while (sample[i])
	{
		res[y] = sample[i];
		i++;
		y++;
	}
	i = 0;
	while (buf[i])
	{
		res[y] = buf[i];
		i++;
		y++;
	}
	res[y] = '\0';
	return (res);
}

int		set_line(char *sample, char buf[BUFFER_SIZE + 1],char **line)
{
	int		i;
	char	*res;

	if (sample == NULL)
	{
		*line = NULL;
		return (0);
	}
	if (!(res = malloc(sizeof(char) * (n_isfound(sample) + 1))))
		return (-1);
	i = 0;
	while (sample[i] != '\n' && sample[i])
	{
		res[i] = sample[i];
		i++;
	}
	res[i] = '\0';
	*line = res;
	return (1);
}