/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:25:50 by skaur             #+#    #+#             */
/*   Updated: 2022/11/24 12:36:41 by skaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *save_line)
{
	int		read_bytes;
	char	*s;

	read_bytes = 0;
	if (!save_line[read_bytes])
		return (NULL);
	while (save_line[read_bytes] && save_line[read_bytes] != '\n')
		read_bytes++;
	s = (char *)malloc(sizeof(char) * (read_bytes + 2));
	if (!s)
		return (NULL);
	read_bytes = 0;
	while (save_line[read_bytes] && save_line[read_bytes] != '\n')
	{
		s[read_bytes] = save_line[read_bytes];
		read_bytes++;
	}
	if (save_line[read_bytes] == '\n')
	{
		s[read_bytes] = save_line[read_bytes];
		read_bytes++;
	}
	s[read_bytes] = '\0';
	return (s);
}

char	*ft_save(char *save_line)
{
	int		read_bytes;
	int		c;
	char	*s;

	read_bytes = 0;
	while (save_line[read_bytes] && save_line[read_bytes] != '\n')
		read_bytes++;
	if (!save_line[read_bytes])
	{
		free(save_line);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save_line) - read_bytes + 1));
	if (!s)
		return (NULL);
	read_bytes++;
	c = 0;
	while (save_line[read_bytes])
		s[c++] = save_line[read_bytes++];
	s[c] = '\0';
	free(save_line);
	return (s);
}

char	*ft_read_and_save(int fd, char *save_line)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save_line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			free(save_line);
			return (NULL);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		save_line = ft_strjoin(save_line, buff);
	}
	free(buff);
	return (save_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save_line = ft_read_and_save(fd, save_line);
	if (!save_line)
		return (NULL);
	line = ft_get_line(save_line);
	save_line = ft_save(save_line);
	return (line);
}
