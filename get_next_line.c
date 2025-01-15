/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mschippe <mschippe@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/27 18:23:50 by mschippe		  #+#	#+#			 */
/*   Updated: 2025/01/06 18:59:42 by mschippe		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

int	read_buffer(int fd, char **buf)
{
	int	bytes_read;

	*buf = malloc(BUFFER_SIZE + 1);
	if (!*buf)
		return (-1);
	bytes_read = read(fd, *buf, BUFFER_SIZE);
	if (bytes_read == -1)
		return (free(*buf), *buf = NULL, bytes_read);
	(*buf)[bytes_read] = '\0';
	*buf = (char *)ft_realloc(*buf, bytes_read + 1, BUFFER_SIZE + 1);
	return (bytes_read);
}

char	*handle_after_newline(char **line, char *newline_pos)
{
	char	*res_to_return;
	char	*old_line_to_free;
	int		aft_nl_len;
	int		line_len;

	line_len = ft_strlen(*line);
	res_to_return = ft_substr(*line, 0, newline_pos - *line + 1);
	if (!res_to_return)
		return (free(*line), *line = NULL, NULL);
	aft_nl_len = ft_strlen(++newline_pos);
	if (aft_nl_len)
	{
		old_line_to_free = *line;
		*line = ft_substr(*line, line_len - aft_nl_len, aft_nl_len);
		free(old_line_to_free);
	}
	else
	{
		free(*line);
		*line = NULL;
	}
	return (res_to_return);
}

char	*handle_last_line(char **line, int size)
{
	char	*res_to_return;

	if (!size)
		return (free(*line), *line = NULL, NULL);
	res_to_return = ft_substr(*line, 0, size);
	if (!res_to_return)
		return (free(*line), *line = NULL, NULL);
	return (free(*line), *line = NULL, res_to_return);
}

char	*ft_get_line(int fd, char **line, char **buffer)
{
	char	*has_newline;
	int		bytes_read;
	int		line_len;

	has_newline = ft_strchr(*line, '\n');
	while (!has_newline)
	{
		line_len = ft_strlen(*line);
		bytes_read = read_buffer(fd, buffer);
		if (bytes_read == -1)
			return (free(*line), *line = NULL, NULL);
		*line = (char *)ft_realloc(*line, line_len + bytes_read + 1, line_len);
		if (!*line)
			return (free(*buffer), buffer = NULL, NULL);
		ft_strlcat(*line, *buffer, ft_strlen(*line) + bytes_read + 1);
		free(*buffer);
		if (bytes_read == 0)
			return (handle_last_line(line, line_len + bytes_read));
		has_newline = ft_strchr(*line, '\n');
	}
	return (handle_after_newline(line, has_newline));
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = NULL;
	return (ft_get_line(fd, &line, &buffer));
}
