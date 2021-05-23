
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>  //for open
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnew(int len)
{
	char	*new_s;

	new_s = (char *)malloc(sizeof(char) * len);
	if (!new_s)
		return (NULL);
	while (len)
	{
		new_s[len] = 0;
		len--;
	}
	return (new_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_1;
	size_t	len_2;
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len_1 = ft_strlen((char *)s1);
	len_2 = ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len_1)
	{
		str[i] = s1[i];
		i++;
	}
	while ((i - len_1) <= len_2)
	{
		str[i] = s2[i - len_1];
		i++;
	}
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == c)
			return ((char *) s + i);
		i++;
	}
	return (NULL);
}

void	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = ft_strlen(src);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char *remainder_line(char *line_end, char **line)
{
	char	*str;

	*line = ft_strnew(1);
	if (line_end)
	{
		if((str = ft_strchr(line_end, '\n')))
		{
			*str = '\0';
			*line = ft_strjoin(*line, line_end);
			str++;
			line_end = str;
			return (line_end);
		}
		else
			*line = ft_strjoin(*line, line_end);
	}
	return (NULL);
}

int	get_next_line (int fd, char **line)
{
	int byte_end;
	char *pointer;
	static char *line_end;
	char *rem;

	*line = ft_strnew(1);
	char	buf[1000 + 1];
	rem = remainder_line(line_end, line);
	line_end = rem;
	while(rem == NULL && (byte_end = read(fd, buf, 1000)))
	{
		if ((pointer = ft_strchr(buf, '\n')))
		{
			*pointer = '\0';
			*line = ft_strjoin(*line, buf);
			pointer++;
			line_end = ft_strjoin(ft_strnew(1), pointer);
		
			return (0);
		}
		buf[byte_end] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}
