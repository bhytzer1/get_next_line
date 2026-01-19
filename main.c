/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandric <dmandric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:40:30 by dmandric          #+#    #+#             */
/*   Updated: 2026/01/19 21:40:46 by dmandric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Errore in apertura file\n");
		return (1);
	}
	i = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linea %d: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
