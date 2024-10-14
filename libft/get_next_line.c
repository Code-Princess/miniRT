/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:50:46 by llacsivy          #+#    #+#             */
/*   Updated: 2024/05/26 19:37:47 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*adjust_buffer(char *old_buffer)
{
	int		buffer_idx;
	int		new_idx;
	char	*new_buffer;

	buffer_idx = 0;
	if (old_buffer == NULL)
		return (free(old_buffer), NULL);
	while (old_buffer[buffer_idx] != '\0' && old_buffer[buffer_idx] != '\n')
		buffer_idx++;
	if (old_buffer[buffer_idx] == '\0')
		return (free(old_buffer), NULL);
	new_buffer = ft_calloc_modified(ft_strlen_modified(old_buffer)
			- buffer_idx + 1, sizeof(char));
	if (new_buffer == NULL)
		return (free(old_buffer), free(new_buffer), NULL);
	buffer_idx++;
	new_idx = 0;
	while (old_buffer[buffer_idx])
		new_buffer[new_idx++] = old_buffer[buffer_idx++];
	new_buffer[new_idx + 1] = '\0';
	return (free(old_buffer), new_buffer);
}

static char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] != '\n')
		line = ft_calloc_modified(i + 1, sizeof(char));
	else
		line = ft_calloc_modified(i + 2, sizeof(char));
	i = 0;
	while (buffer[i])
	{
		line[i] = buffer[i];
		if (line[i] == '\n')
		{
			i++;
			line[i] = 0;
			break ;
		}
		i++;
	}
	return (line);
}

char	*read_from_fd_into_buffer(int fd, char *buffer)
{
	int		read_size;
	char	*tmp;

	tmp = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!tmp)
		return (free(buffer), NULL);
	read_size = read(fd, tmp, BUFFER_SIZE);
	if (read_size == -1)
		return (free(tmp), free(buffer), NULL);
	while (read_size > 0)
	{
		buffer = ft_strjoin_modified(buffer, tmp, read_size);
		if (buffer && ft_strchr(buffer, '\n'))
			break ;
		read_size = read(fd, tmp, BUFFER_SIZE);
		if (read_size == -1)
			return (free(tmp), tmp = NULL, free(buffer), NULL);
	}
	free(tmp);
	tmp = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), buffer = NULL, NULL);
	buffer = read_from_fd_into_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = adjust_buffer(buffer);
	return (line);
}
