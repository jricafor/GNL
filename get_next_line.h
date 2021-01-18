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
#  define BUFFER_SIZE 4096
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);

int		ft_strlen(char *str);
int		n_isfound(char *sample);
char	*flegma(char *src, int offset);
char	*append_sample(char *sample, char buf[BUFFER_SIZE + 1]);
int		set_line(char *sample, char buf[BUFFER_SIZE + 1],char **line);


#endif
