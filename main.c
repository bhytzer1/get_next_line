/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandric <dmandric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 22:23:25 by dmandric          #+#    #+#             */
/*   Updated: 2026/01/19 22:29:06 by dmandric         ###   ########.fr       */
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
		printf("Errore nell'apertura del file\n");
		return (1);
	}
	i = 1;
	printf("Inizio lettura...\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linea %d: %s", i, line);
		free(line);
		printf("Liberata linea %d\n", i);
		i++;
	}
	printf("Fine lettura\n");
	close(fd);
	return (0);
}
