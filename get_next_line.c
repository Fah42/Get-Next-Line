/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:48:14 by fhadhri           #+#    #+#             */
/*   Updated: 2022/06/23 19:04:49 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_before(const char *str)
{
	int		i;
	char	*string;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] != '\n')
		i++;
	string = malloc((i + 2) * sizeof(char));
	if (string == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		string[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		string[i] = '\n';
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_after(char *str)
{
	int		n;
	int		i;
	char	*string;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		safe_free(str);
		return (NULL);
	}
	n = ft_strlen(str);
	string = malloc((n - i) * sizeof(char));
	if (string == NULL)
		return (NULL);
	n = 0;
	i++;
	while (str[i] != '\0')
		string[n++] = str[i++];
	string[n] = '\0';
	safe_free(str);
	return (string);
}

int	ft_newline(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read(int fd, char *buffer, char *tmp, char *str)
{
	int	bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		tmp = str;
		if (tmp == NULL)
		{
			tmp = malloc(sizeof(char));
			tmp[0] = '\0';
		}
		str = ft_strjoin(tmp, buffer);
		safe_free(tmp);
		if (ft_newline(str) == 1 || bytes_read == 0)
			break ;
	}
	safe_free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*ligne;
	char		*tmp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	tmp = NULL;
	str = ft_read(fd, buffer, tmp, str);
	if (str == NULL)
		return (NULL);
	ligne = ft_before(str);
	str = ft_after(str);
	return (ligne);
}

int	main(void)
{
	int	fd;
	char *ligne;

	fd = open("LOL.txt", O_RDONLY);
	ligne = get_next_line(fd);
	// // printf("1e ligne = %s", ligne);
	// ligne = get_next_line(fd);
	// // printf("2e ligne = %s", ligne);
	// ligne = get_next_line(fd);
	// // printf("3e ligne = %s", ligne);
	return (0);
}
