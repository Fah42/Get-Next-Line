/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:48:14 by fhadhri           #+#    #+#             */
/*   Updated: 2022/06/20 14:55:02 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	int			c_size;
	int			string_size;
	static char	c[BUFFER_SIZE + 1];
	char		*string;

	i = 0;
	c_size = 0;
	string_size = 0;
	read(fd, c, BUFFER_SIZE);
	c_size = ft_strlen(c);
	c[c_size + 1] = '\0';
	while (string[i] != '\n')
	{
		string = ft_strjoin(string, c);
		read(fd, c, BUFFER_SIZE);
		i++;
	}
	string_size = ft_strlen(string);
	printf("%d\n", string_size);
	printf("%s", string);
	return (string);
}

int	main(void)
{
	int	fd;

	fd = open("LOL.txt", O_RDONLY);
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	get_next_line(fd);
	return (0);
}
