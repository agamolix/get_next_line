/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:35:18 by atrilles          #+#    #+#             */
/*   Updated: 2022/02/08 16:14:27 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *part1(char *s, int index)
{   
    char    *res;

    res = malloc(index * sizeof(char));
    while (index >= 0)
    {   
        res[index] = s[index];
        index--;
    }
    return (res);
}

char    *part2(char *s, int index)
{   
    char    *res;
    int i;

    i = 0;
    res = malloc((ft_strlen(s) - index + 1) * sizeof(char));
    while (s[index + i + 1])
    {   
        res[i] = s[index + i + 1];
        i++;
    }
    return (res);
}

char *update_temp_line (char *temp, char **line, int switch_case, int fd)
{
    if (switch_case == 1)
    {
        line[0] = ft_strjoin(line[0], part1(temp, index_nl(temp)));
        if (ft_strlen(temp) == index_nl(temp) + 1)
            return (0);
        else 
            return (part2(temp, index_nl(temp)));
    }
    else 
    {
        line[0] = ft_strjoin(line[0], temp);
        read(fd, temp, BUFFER_SIZE);
        return (temp);
    }
}

void    init_free(char **line, char **buf, int switch_case)
{
    if (switch_case == 1)
    {
        line[0] = 0;
        buf[0] = malloc((BUFFER_SIZE + 1) * sizeof(char));
    }
    else
        free(buf[0]);
}

char *get_next_line(int fd)
{
    char *line;
    char *buf;
    static char *temp;

    if (BUFFER_SIZE == 0)
        return (0);
    init_free(&line, &buf, 1);
    while (temp == 0 || index_nl(temp) < 0)
    {
        if(read(fd, buf, BUFFER_SIZE) < 1)
            return 0;
        temp = ft_strjoin(temp, buf);
    }
    while(temp)
    {
        if (index_nl(temp) >= 0)
        {
            temp = update_temp_line(temp, &line, 1, fd);
            return(line);
        }
        if (index_nl(temp) < 0)
            temp = update_temp_line(temp, &line, 2, fd);
    }
    init_free(&line, &buf, 2);
}