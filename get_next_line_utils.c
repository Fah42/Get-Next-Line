/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhadhri <fhadhri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:51:58 by fhadhri           #+#    #+#             */
/*   Updated: 2022/05/20 22:28:46 by fhadhri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



size_t	ft_strlen(const char *s)
{
	const char	*str;
	int			i;

	i = 0;
	str = s;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	d;
	const char		*ss;
	int				i;

	d = (unsigned char)c;
	ss = s;
	i = 0;
	while (ss[i] != '\0')
	{
		if (ss[i] == d)
			return ((char *)&s[i]);
	i++;
	}
	if (ss[i] == d)
		return ((char *)&s[i]);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		max;
	int		i;
	int		j;

	j = 0;
	i = 0;
	max = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *) malloc(sizeof(char) * max + 1);
	while (s1[i])
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		dest[j] = s2[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
