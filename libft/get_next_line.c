/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 23:23:17 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/09 12:43:49 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*move_buffer(char *buffer, char *ptr)
{
	size_t	step;
	size_t	i;

	step = (ptr - buffer);
	i = step;
	while (i <= BUFFER_SIZE)
	{
		buffer[i - step] = buffer[i];
		buffer[i] = 0;
		i++;
	}
	i = BUFFER_SIZE - step;
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
	return (NULL);
}

char	*return_line(char *line, char *buffer, char *nlf_ptr)
{
	char	*new;
	size_t	needed;

	needed = nlf_ptr - buffer + 1;
	if (line)
		needed += ft_strlen(line);
	new = malloc((needed + 1) * sizeof(char));
	if (!new || needed < 1)
	{
		free(new);
		free(line);
		return (NULL);
	}
	new[0] = 0;
	if (line && ft_strlen(line) > 0)
		ft_strlcpy(new, line, needed + 1);
	ft_strlcat(new, buffer, needed + 1);
	move_buffer(buffer, nlf_ptr + 1);
	free(line);
	return (new);
}

char	*append_to_line(char *buffer, char *line)
{
	char	*aux;

	if (!line)
	{
		line = ft_strdup(buffer);
	}
	else
	{
		aux = line;
		line = ft_strjoin(aux, buffer);
		free(aux);
	}
	move_buffer(buffer, buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*line;
	char		*c;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (move_buffer(buffer[fd], buffer[fd]));
	line = NULL;
	c = ft_strchr(buffer[fd], '\n');
	if (c != NULL)
		return (return_line(line, buffer[fd], c));
	if (ft_strlen(buffer[fd]) > 0)
		line = append_to_line(buffer[fd], line);
	while (read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		c = ft_strchr(buffer[fd], '\n');
		if (c != NULL)
			return (return_line(line, buffer[fd], c));
		line = append_to_line(buffer[fd], line);
	}
	if (line && ft_strlen(line) > 0)
		return (line);
	free(line);
	return (move_buffer(buffer[fd], buffer[fd]));
}
