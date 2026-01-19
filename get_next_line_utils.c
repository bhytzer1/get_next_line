/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davide <davide@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 00:32:25 by davide            #+#    #+#             */
/*   Updated: 2026/01/19 01:28:31 by davide           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	if(!c || !str)
		return (0);
	while(str[i])
	{
		if(str[i] == c)
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	if(!str)
		return(0);
	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i1;
	size_t	i2;
	char	*c;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	c = malloc(sizeof(char) * (i1 + i2 + 1));
	if(!c)
		return (NULL);
	i1 = -1;
	if (s1)
		while(s1[++i1])
			c[i1] = s1[i1];
	i2 = -1;
	while (s2[++i2])
		c[i1 + i2] = s2[i2];
	c[i1 + i2] = '\0';
	if (s1)
		free (s1);
	return (c);
}
