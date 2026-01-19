/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandric <dmandric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:38:29 by dmandric          #+#    #+#             */
/*   Updated: 2026/01/19 21:39:29 by dmandric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 ^Estrae la prima linea dal buffer statico
*/
char	*extract_line(char *stat_buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!stat_buf || !stat_buf[0])
		return (NULL);
	while (stat_buf[i] && stat_buf[i] != '\n')
		i++;
	if (stat_buf[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stat_buf[i] && stat_buf[i] != '\n')
	{
		line[i] = stat_buf[i];
		i++;
	}
	if (stat_buf[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/*
 ^Salva il resto del buffer dopo la linea estratta
*/
char	*save_rest(char *stat_buf)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (stat_buf[i] && stat_buf[i] != '\n')
		i++;
	if (!stat_buf[i])
	{
		free(stat_buf);
		return (NULL);
	}
	i++;
	rest = malloc(sizeof(char) * (ft_strlen(stat_buf) - i + 1));
	if (!rest)
		return (NULL);
	j = 0;
	while (stat_buf[i])
		rest[j++] = stat_buf[i++];
	rest[j] = '\0';
	free(stat_buf);
	return (rest);
}

/*
 ^Legge dal file e accumula nel buffer statico
*/
char	*read_file(int fd, char *stat_buf)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stat_buf, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stat_buf);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stat_buf = ft_strjoin(stat_buf, buffer);
	}
	free(buffer);
	return (stat_buf);
}

/*
 ^Funzione principale che legge una linea dal file descriptor
*/
char	*get_next_line(int fd)
{
	static char	*stat_buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat_buf = read_file(fd, stat_buf);
	if (!stat_buf)
		return (NULL);
	line = extract_line(stat_buf);
	stat_buf = save_rest(stat_buf);
	return (line);
}
