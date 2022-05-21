/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:48:14 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/21 19:57:40 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ft_get_read_size(fd, tab, nbyte)
{
	int	d;

	buffer_size = 0;
	nbyte = 5;
	d = read(fd, tab, nbyte);
	if (!fd || fd <= 0 || fd > 1023)
		return (NULL);
	while (i != 0)
	{
		i = read(fd, tab, nbyte);
		buffer_size += i;
	}
	return (buffer_size)
}

char	*get_next_line(int fd)
{
	char	*tab;
	int		buffer_size;
	int		nbyte;
	int		i;

	buffer_size = ft_get_read_size(fd, );
	nbyte = 5;
	i = read(fd, tab, nbyte);
	if (!fd || fd <= 0 || fd > 1023)
		return (NULL);
	while (i != 0)
	{
		i = read(fd, tab, nbyte);
		buffer_size += i;
	}
	tab = (char *) malloc(sizeof(char) * buffer_size);
	while (i != 0)
	{
		i = read(fd, tab, nbyte);
		printf("value of i : %d\n", i);
		printf("value of bufferSize : %d\n", buffer_size);
		printf("%s", tab);
	}
}

int	main(void)
{
	int 	fd, sz;
	char 	*c = (char *) calloc(100, sizeof(char));

	fd = open("LOL.txt", O_RDONLY);
	get_next_line(fd);
}
