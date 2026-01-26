/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandric <dmandric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 22:23:25 by dmandric          #+#    #+#             */
/*   Updated: 2026/01/26 14:15:29 by dmandric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// int	main(void)
// {
// 	int		fd, fd1, fd2;
// 	char	*line;
// 	int		i;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Errore nell'apertura del file\n");
// 		return (1);
// 	}
// 	fd1 = open("test2.txt", O_RDONLY);
// 	i = 1;
// 	printf("inzio lettura...\n");
// 	while ((line = get_next_line(fd1)) != NULL)
// 	{
// 		printf("Linea %d: %s", i, line);
// 		free(line);
// 		printf("Liberata linea %d\n", i);
// 		i++;
// 	}
// 	fd2 = open("test3.txt", O_RDONLY);
// 	i = 1;
// 	printf("Inizio lettura2...\n");
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Linea %d: %s", i, line);
// 		free(line);
// 		printf("Liberata linea %d\n", i);
// 		i++;
// 	}
// 	i = 1;
// 	printf("inizio lettura 3...\n");
// 	while((line = get_next_line(fd2)) != NULL)
// 	{
// 		printf("linea %d: %s", i, line);
// 		free(line);
// 		printf("liberata linea %d\n", i);
// 		i++;
// 	}
// 	printf("Fine lettura\n");
// 	close(fd1);
// 	close(fd);
// 	return (0);
// }
