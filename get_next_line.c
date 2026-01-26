/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandric <dmandric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 22:22:21 by dmandric          #+#    #+#             */
/*   Updated: 2026/01/26 14:15:13 by dmandric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 ^legge la prima riga del buffer statico
*/

char	*ft_read_from_file(char *res_static, int fd)
{
	int		bytes_letti;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_letti = 1;
	while (!ft_strchr(res_static, '\n') && bytes_letti != 0)
	{
		bytes_letti = read(fd, buffer, BUFFER_SIZE);
		if (bytes_letti == -1)
		{
			free (buffer);
			if (res_static)
				free (res_static);
			return (NULL);
		}
		buffer[bytes_letti] = '\0';
		res_static = ft_strjoin(res_static, buffer);
	}
	free (buffer);
	return (res_static);
}

/*
 ^Salva il resto del buffer dopo la linea estratta
*/

char	*ft_get_line(char *res_static)
{
	int		i;
	char	*line;

	if (!res_static || !res_static[0])
		return (NULL);
	i = 0;
	while (res_static[i] != '\n' && res_static[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (res_static[i] != '\n' && res_static[i])
	{
		line[i] = res_static[i];
		i++;
	}
	if (res_static[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*
 ^Legge dal file e accumula nel buffer statico (greve)
*/

char	*ft_new_static(char *res_static)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (res_static[i] != '\n' && res_static[i])
		i++;
	if (!res_static[i])
	{
		free (res_static);
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(res_static) - i + 1));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (res_static[i])
		line[j++] = res_static[i++];
	line[j] = '\0';
	free (res_static);
	return (line);
}

/*
 ^Funzione che legge una linea dal file descriptor (follia)
*/

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_from_file(stash, fd);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_new_static(stash);
	return (line);
}
