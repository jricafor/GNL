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
	if (buf[i] == '\0')
	 	return (0);
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	*line = NULL;
	*line = malloc(sizeof(char) * (i - start) + 1);
	*line = set_line(buf, start, i);
	if (buf[i + 1] && buf[i] == '\n')
		i++;
	return (i);
}