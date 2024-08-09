/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:23:22 by chaoh             #+#    #+#             */
/*   Updated: 2024/07/15 20:38:45 by chaerin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_the_rest(char *line)
{
	char	*the_rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	the_rest = (char *)malloc(sizeof(char) * (gnl_strlen(line) - i + 1));
	if (the_rest == NULL)
		return (NULL);
	while (line[i] != '\0')
	{
		the_rest[j] = line[i];
		i++;
		j++;
	}
	the_rest[j] = '\0';
	return (the_rest);
}

char	*make_a_line(char *line)
{
	char	*rt_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (line == NULL)
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (!(gnl_strchr(line, '\n')))
		rt_line = (char *)malloc(sizeof(char) * (i + 1));
	else
		rt_line = (char *)malloc(sizeof(char) * (i + 2));
	if (rt_line == NULL)
		return (NULL);
	i = 0;
	if (line[0] == '\n')
		i++;
	while (line[i] && line[i] != '\n')
		rt_line[j++] = line[i++];
	if (line[i] == '\n')
		rt_line[j] = '\n';
	return (rt_line);
}

char	*get_a_line(int fd, char *line)
{
	int		read_bytes;
	char	*buff;

	if (line == NULL)
		line = gnl_strdup("");
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == 0 || read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		line = gnl_strjoin(line, buff);
		if (gnl_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer_line;
	static char	*next_line;

	line = "";
	buffer_line = "";
	if (!next_line)
		next_line = gnl_strdup("");
	else
		buffer_line = gnl_strdup(next_line);
	buffer_line = get_a_line(fd, buffer_line);
	if (buffer_line == NULL)
		return (NULL);
	line = make_a_line(buffer_line);
	next_line = save_the_rest(buffer_line);
	return (line);
}
