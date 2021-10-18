#include "get_next_line.h"
#include <errno.h>
#include <stdio.h>


char *get_line_from_memo(char **memo, const char *tail_ptr)
{
	char *new_line;
	char *second_line;

	if (*memo == NULL)
		return (NULL);
	new_line = ft_substr(*memo, 0, tail_ptr - *memo + 1);
	second_line = ft_substr(tail_ptr, 1, SIZE_MAX / 4LL);
	free(*memo);
	*memo = NULL;
	if (second_line == NULL || second_line[0] == '\0')
	{
		free(second_line);
		second_line = NULL;
	}
	else
		*memo = second_line;
	return (new_line);
}

char *get_next_line(int fd)
{
	static char *memo[FD_SIZE];
	char *buf;
	ssize_t read_size;
	char *next_line_ptr;

	if (memo[fd] != NULL)
		next_line_ptr = ft_strchr(memo[fd], '\n');
	if (next_line_ptr != NULL && memo[fd] != NULL)
		return (get_line_from_memo(&memo[fd], next_line_ptr));
	while (1)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1LL));
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			return (NULL);
		buf[read_size] = '\0';
		if (read_size == 0)
		{
			next_line_ptr = memo[fd] + ft_strlen(memo[fd]);
			return (get_line_from_memo(&memo[fd], next_line_ptr));
		}
		memo[fd] = ft_strjoin(memo[fd], buf);
		next_line_ptr = ft_strchr(memo[fd], '\n');
		if (next_line_ptr != NULL)
			return (get_line_from_memo(&memo[fd], next_line_ptr));
	}
	return (NULL);
}

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	const size_t src_len = ft_strlen(src);
	size_t i;

	if (dst == NULL || src == NULL)
		return (0);
	i = 0;
	if (src_len + 1 < size)
	{
		while (i < src_len + 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else if (size > 0)
	{
		while (i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[size - 1] = '\0';
	}
	return (src_len);
}
