/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcavillo <fcavillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:11:32 by fcavillo          #+#    #+#             */
/*   Updated: 2020/05/07 16:23:56 by fcavillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int				get_next_line(int fd, char **line);

int main()
{
	int             fd;
	int				a = 0;
	char    		*line;


	if (!(fd = open("ex.txt", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((a = (get_next_line(fd, &line)) > 0))
	{
		printf("%d ", a);
		printf("%s\n", line);
	}
	printf("%d\n", a);
	free(line);
	close(fd);
}
