/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmandric <dmandric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:43:41 by dmandric          #+#    #+#             */
/*   Updated: 2026/01/26 14:21:28 by dmandric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
^prende una stringa e un char e ritorna la posizione del char che gli diamo
*/

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || c == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}
/*
^non credo di dover spiegare questa...
*/

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
^classico strjoin ma che che gestisce anche la memoria
*/

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*c;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	c = malloc(sizeof(char) * (i + j + 1));
	if (!c)
		return (NULL);
	i = -1;
	if (s1)
		while (s1[++i])
			c[i] = s1[i];
	else
		i = 0;
	j = -1;
	if (s2)
		while (s2[++j])
			c[i + j] = s2[j];
	c[i + j] = '\0';
	if (s1)
		free (s1);
	return (c);
}
