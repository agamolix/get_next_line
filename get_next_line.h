/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/02/15 11:52:23 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


int    ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int index_nl(char *s);

char    *part1(char *s, int index);
char    *part2(char *s, int index);
char *update_temp_line (char *temp, char **line, int switch_case, int fd);
void    init_free(char **line, char **buf, int switch_case);
char *get_next_line(int fd);

#endif
