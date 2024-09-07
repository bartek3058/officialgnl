/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:37:13 by brogalsk          #+#    #+#             */
/*   Updated: 2024/09/04 13:24:51 by brogalsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = c;
		n--;
		p++;
	}
	return (s);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dst;
	int		i;

	i = 0;
	len = ft_strlen(s);
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	a;
	char	*dest;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = start;
	a = 0;
	while (len > 0 && s[i] != '\0')
	{
		dest[a] = s[i];
		i++;
		a++;
		len--;
	}
	dest[a] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	char	*s3;
	char	*s4;
	int		i;
	int		a;

	i = 0;
	a = 0;
	s3 = (char *)s1;
	s4 = (char *)s2;
	d = (char *)malloc(ft_strlen(s3) + ft_strlen(s4) + 1);
	if (d == NULL)
		return (0);
	while (s3[i] != '\0')
		d[i++] = s3[a++];
	a = 0;
	while (s4[a] != '\0')
		d[i++] = s4[a++];
	d[i] = '\0';
	return (d);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*a;
	char	cc;

	cc = (char)c;
	a = (char *)s;
	i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == cc)
			return (&a[i]);
		i++;
	}
	if (a[i] == cc)
		return (&a[i]);
	return (NULL);
}
