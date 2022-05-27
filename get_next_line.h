/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/05/24 11:16:58 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

// get_next_line_utils
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		index_nl(char *s);

// get_next_line
char	*part1(char *s, int index);
char	*part2(char *s, int index);
char	*update_temp_line(char *temp, char **line, int switch_case, int fd);
void	init_free(char **line, char **buf, int switch_case);
char	*get_next_line(int fd);

#endif
