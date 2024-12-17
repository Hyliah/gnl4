/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:33:39 by hlichten          #+#    #+#             */
/*   Updated: 2024/12/16 19:41:07 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	s;
	unsigned int	i;

	s = 0;
	i = 0;
	while (src && src[s] != '\0')
		s++;
	if (size == 0)
		return (s);
	while (src && src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(str, s1, len_s1 + 1);
		free(s1);
	}
	ft_strlcpy(str + len_s1, s2, len_s2 + 1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	d;

	d = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == d)
			return ((char *) s);
		s++;
	}
	if (d == '\0')
		return ((char *) s);
	return (NULL);
}
