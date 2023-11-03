#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*t;

	i = 0;
	j = -1;
	while (s1[i])
		i++;
	t = malloc((i + 1) * sizeof(char));
	if (!t)
		return (0);
	while (s1[++j])
	{
		t[j] = s1[j];
	}
	t[j] = '\0';
	return (t);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*str;
	int		i;
	int		j;

	if (s1 && !s2)
		return ((char *)s1);
	if (!s1 && s2)
		return ((char *)s2);
	if (!s1 && !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(total_len * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	char	*ptr;

	ptr = s;
	while (*ptr)
	{
		if (*ptr == (unsigned char) c && *(ptr + 1))
			return (ptr + 1);
		ptr++;
	}
	if (*ptr == '\0' && c == '\0')
		return (ptr);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	size_t			count;
	size_t			real;

	if (!s)
		return (NULL);
	count = ft_strlen(s);
	real = count;
	if ((size_t)start >= count || len == 0)
		return (ft_strdup(""));
	i = 0;
	if (count > len)
		real = len;
	str = (char *)malloc(sizeof(char) * (real + 1));
	if (!str)
		return (0);
	while ((size_t)i < real && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
	size_t		bytes_read;
	size_t		buffer;
	int			i;
	static char	*str;
	char		*fullstr;

    buffer = 3;
	str = (char *) malloc(buffer * sizeof(char));
	bytes_read = buffer;
	fullstr = "";
	i = -1;
    while (buffer <= bytes_read)
    {
		if (!ft_strchr(str, '\n'))
	    	bytes_read = read(fd, str, buffer);
		while (str[++i])
		{
			if (str[i] == '\n')
				break ;
		}
		fullstr = ft_strjoin((char const *)fullstr, (char const *)ft_substr((char const *)str, 0, (size_t) (i + 1)));
		if (ft_strchr(str, '\n'))
		{
			str = ft_strchr(str, '\n');
			return (fullstr);
		}
    }
	return (fullstr);
}

int	main(void)
{
	int		fd;

    fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		write(1, "Error!\n", 7);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}