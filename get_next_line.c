/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:48:14 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/24 21:52:24 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		sz;
	int		BUFFER_SIZE;
	char	*c;
	int		i;
	char	*str;

	str = (char *) malloc(sizeof(char) * 1000000);
	c = (char *) malloc(sizeof(char) * 1000000);
	i = 0;
	BUFFER_SIZE = 1;
	sz = read(fd, c, BUFFER_SIZE);
	c[sz] = '\0';
	while (sz != 0)
	{
		
		printf("%c" ,c[i]);
		i++;
	}
}

int main()
{
	int fd;

	fd = open("LOL.txt", O_RDONLY);
	get_next_line(fd);
} 