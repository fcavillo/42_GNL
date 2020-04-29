/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcavillo <fcavillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:57:38 by fcavillo          #+#    #+#             */
/*   Updated: 2020/04/29 15:57:45 by fcavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(char const *s)
{
	size_t			len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int a;

	a = 0;
	while (s[a])
	{
		if (s[a] == c)
		{
			return ((char *)&(s[a]));
		}
		a++;
	}
	if (s[a] == '\0' && c == '\0')
		return ((char *)&(s[a]));
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	a;
	unsigned int	size;
	char			*tab;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(tab = malloc(sizeof(*tab) * (len + 1))))
		return (NULL);
	a = 0;
	while (a < len)
	{
		tab[a] = s[start + a];
		a++;
	}
	tab[a] = '\0';
	return (tab);
}

char	*ft_strdup(const char *s)
{
	int		a;
	char	*tab;

	a = 0;
	while (s[a])
		a++;
	if (!(tab = malloc(sizeof(*tab) * (a + 1))))
		return (NULL);
	a = 0;
	while (s[a])
	{
		tab[a] = s[a];
		a++;
	}
	tab[a] = '\0';
	return (tab);
}

void	ft_freestr(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
}
