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
	static char		*sample = NULL;
	static char		*tmp = NULL;

	sample = tmp;
	printf("sample: %s\n", sample);
	while (n_isfound(sample) <= 0 && (bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		if (sample != NULL)
			tmp = flegma(sample, 0);	
		if (!(sample = malloc(sizeof(char) * (ft_strlen(sample) + BUFFER_SIZE + 1))))
			return (-1);
		sample = append_sample(tmp, buf);
		if (sample == NULL)
			return (-1);
	}
	if (n_isfound(sample) && sample)
		tmp = flegma(sample, n_isfound(sample) + 1);
	else
		tmp = NULL;
	printf("tmp: %s\n", tmp);
	return (set_line(sample, buf, line));
}
