/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:21:57 by hlichten          #+#    #+#             */
/*   Updated: 2024/12/16 19:46:02 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **line)
{
	free(*line);
	*line = NULL;
	return (NULL);
}

int	update_line(char *buffer, char **line)
{
	char	*newline_pos;

	newline_pos = ft_strchr(buffer, '\n');
	if (newline_pos != NULL)
	{
		*newline_pos = '\0';
		if (!(*line = ft_strjoin(*line, buffer)) || 
		!(*line = ft_strjoin(*line, "\n")))
			return (0);
		ft_strlcpy(buffer, newline_pos + 1, BUFFER_SIZE - (newline_pos - buffer));
		return (1);
	}
	if (!(*line = ft_strjoin(*line, buffer)))
		return (0);
	buffer[0] = '\0';
	return (0);
}
int	is_eof(int rd, char *buffer, char **line)
{
	if (rd < 0)
		return (1);
	if (rd == 0 && !*line && buffer[0] == '\0')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*line;
	int			rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[0] == '\0')
		{
			rd = read(fd, buffer, BUFFER_SIZE);
			if (rd >= 0)
				buffer[rd] = '\0';
			if (is_eof(rd, buffer, &line))
				return (ft_free(&line));
		}
		if (update_line(buffer, &line))
			return (line);
		if (rd == 0)
			break ;
	}
	return (line);
}

// int    main (int ac, char **av)
// {
//     int     fd;
//     char    *line;

//     fd = open(*(++ av), O_RDONLY);
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free (line);
//     }
// 	return 0;
// }