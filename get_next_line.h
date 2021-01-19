/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jricafor <jricafor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:40:21 by jricafor          #+#    #+#             */
/*   Updated: 2020/10/01 11:43:23 by jricafor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);

int		ft_strlen(char *str);
int		looping(char *sample);
char	*flegma(char *src, int start, int end);
char	*append_sample(char *sample, char buf[BUFFER_SIZE + 1]);
int		set_line(char *sample, char **line, char **tmp);

#endif
