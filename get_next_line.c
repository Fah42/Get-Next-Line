/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:48:14 by fhadhri           #+#    #+#             */
/*   Updated: 2022/06/21 15:03:32 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line.h"

int	checkn(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			rr;
	static char	sstr[BUFFER_SIZE + 1];
	char		*string;

	rr = 1;
	while (rr != 0)
	{
		if(checkn(sstr) == 0)
		{
			rr = read(fd, sstr, BUFFER_SIZE);
			sstr[rr] = '\0';
			string = ft_strjoin(string, sstr);
			printf("string vaut = %s\n", string);
		}
		else
		{
			//rr = read(fd, sstr, BUFFER_SIZE);
			break ;
		}
	}
	return (string);
}

int	main(void)
{
	int	fd;
	char *ligne;

	fd = open("LOL.txt", O_RDONLY);
	ligne = get_next_line(fd);
	printf("1e ligne = [%s]", ligne);
	// free(ligne);
	ligne = get_next_line(fd);
	printf("2e ligne = [%s]", ligne);
free(ligne);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	return (0);
}
