/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:07:14 by fhadhri           #+#    #+#             */
/*   Updated: 2022/06/27 10:08:12 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*ligne;

	fd = open("LOL.txt", O_RDONLY);
	ligne = get_next_line(fd);
	printf("1e ligne = %s\n", ligne);
	free(ligne);
	ligne = get_next_line(fd);
	printf("2e ligne = %s", ligne);
	free(ligne);
	return (0);
}
