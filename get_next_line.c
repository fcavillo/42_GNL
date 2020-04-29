/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcavillo <fcavillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:58:49 by fcavillo          #+#    #+#             */
/*   Updated: 2020/04/29 16:00:53 by fcavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	size_t		i;
	size_t		src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_gnlstrjoin(char *s1, char *s2)
{
	char		*result;
	size_t		len_s1;
	size_t		len_s2;
	size_t		len;

	len_s1 = 0;
	len_s2 = ft_strlen(s2);
	if (s1)
		len_s1 = ft_strlen(s1);
	len = len_s1 + len_s2;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(result, s1, (len_s1 + 1));
		ft_freestr(&s1);
	}
	ft_strlcpy(result + len_s1, s2, (len_s2 + 1));
	return (result);
}

int		is_line(char **s, char **line)
{
	int		len;
	char	*tmp;
	int		i;

	len = 0;
	i = 0;
	tmp = NULL;
	if ((tmp = ft_strchr(*s, '\n')))
	{
		i = ft_strlen(*s) - ft_strlen(tmp);
		len = ft_strlen(tmp);
		*line = ft_substr(*s, 0, i);
		ft_strlcpy(*s, (tmp + 1), (len + 1));
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			read_nb;
	char		buffer[BUFFER_SIZE + 1];
	static char	*tmp;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (tmp && is_line(&tmp, line))
		return (1);
	while ((read_nb = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_nb] = '\0';
		if (!(tmp = ft_gnlstrjoin(tmp, buffer)))
			return (-1);
		if (is_line(&tmp, line))
			return (1);
	}
	if (tmp && *tmp)
		*line = ft_strdup(tmp);
	else if (read_nb == -1 || read_nb == 0)
		*line = ft_strdup("");
	ft_freestr(&tmp);
	return (read_nb);
}
