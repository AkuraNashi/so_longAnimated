/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecamilo <lecamilo@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:28:51 by lcamilo-          #+#    #+#             */
/*   Updated: 2025/10/20 13:36:05 by lecamilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

//gnl.c
char	*get_next_line(int fd);
int		read_buffer(char *buffer);
void	free_buffer(char **buffer, int fd);
int		read_line(char **line, int fd, int i);
//gnl_utils.c
char	*ft_strlendup(const char *s, int i);
char	*ft_strlenjoin(char const *s1, char const *s2, int i);
#endif

