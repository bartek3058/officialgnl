/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:36:45 by brogalsk          #+#    #+#             */
/*   Updated: 2024/09/04 13:32:52 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;

	if (nmemb > SIZE_MAX / size)
		return (0);
	dst = (void *)malloc(nmemb * size);
	if (!dst)
		return (NULL);
	ft_memset (dst, 0, nmemb * size);
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	int		a;
	size_t	b;

	a = 0;
	b = 0;
	while (s[a] != '\0')
	{
		a++;
		b++;
	}
	return (b);
}

static char	*read_one_line(int fd, char *text, char *buffer)
{
	int		read_line;
	char	*temp;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, text, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		text[read_line] = '\0';
		if (!buffer)
			buffer = ft_strdup("");
		temp = buffer;
		buffer = ft_strjoin(temp, text);
		free(temp);
		if (ft_strchr(text, '\n'))
			break ;
	}
	return (buffer);
}

static char	*ft_count(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\0' && line[count] != '\n')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*text;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = ft_calloc (sizeof (char), BUFFER_SIZE + 1);
	if (!text)
		return (NULL);
	line = read_one_line(fd, text, buffer);
	free(text);
	text = NULL;
	if (!line)
		return (NULL);
	buffer = ft_count(line);
	return (line);
}
/*int main ()
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	return(0);
}*/
