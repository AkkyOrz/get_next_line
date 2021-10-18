#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>

# define FD_SIZE 65536
// # define BUFFER_SIZE 10

size_t ft_strlen(const char *str);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s);
char *ft_strchr(const char *s, int c);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *get_next_line(int fd);
char *get_line_from_memo(char **memo, const char *tail_ptr);
#endif
