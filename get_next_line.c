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
		if (*ptr == (unsigned char) c)
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
	size_t			bytes_read;
	int				i;
	char			*fullstr;
	static char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, str, 0))
		return (NULL);
	if (!str)
		fullstr = "";
	else
		fullstr = ft_strdup(str);
	str = (char *) malloc(BUFFER_SIZE * sizeof(char) + 1);
	bytes_read = BUFFER_SIZE;
	i = -1;
    while (BUFFER_SIZE <= bytes_read)
    {
		i = 0;
		if (!ft_strchr(str, '\n'))
		{
	    	bytes_read = read(fd, str, BUFFER_SIZE);
			str[bytes_read] = '\0';
		}
		else
			fullstr = "";
		// if (ft_strlen(str) > buffer)
		// 	str = ft_substr((char const *)str, 0, bytes_read);
		// printf("str after first if in while: --%s--\n", str);
		// printf("fullstr after first if in while: %s\n", fullstr);
		while (str[i] && str[i] != '\n')
			i++;
		// printf("%d\n", i);
		// if (bytes_read >= buffer)
		// 	fullstr = ft_strjoin((char const *)fullstr, (char const *)ft_substr((char const *)str, 0, (size_t) i + 1));
		fullstr = ft_strjoin((char const *)fullstr, (char const *)ft_substr((char const *)str, 0, (size_t) i + 1));
		if (ft_strchr(str, '\n'))
		{
			str = ft_strchr(str, '\n');
			return (fullstr);
		}
    }
	free(str);
	return (fullstr);
}

// char *create_line(t_list **begin)
// {
// 	t_list	*tmp;
// 	int		count;
// 	char	*str;
// 	int		len;

// 	if (!*begin)
// 		return (NULL);
// 	count = 1;
// 	tmp = *begin;
// 	while (tmp)
// 	{
// 		tmp = tmp->next;
// 		count++;
// 	}
// 	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE * count + 1));
// 	len = 0;
// 	count = 0;
// 	while((*begin)->str[len])
// 	{
// 		str[BUFFER_SIZE * count + len] = (*begin)->str[len];
// 		if ((*begin)->str[len] == '\n')
// 		{
// 			str[BUFFER_SIZE * count + len + 1] = '\0';
// 			(*begin)->str = ft_strchr((*begin)->str, '\n');
// 			return (str);
// 		}
// 		len++;
// 		if (len == BUFFER_SIZE || len == (int) ft_strlen((*begin)->str))
// 		{
// 			printf("%d\n", len);
// 			len = 0;
// 			count++;
// 			tmp = *begin;
// 			*begin = (*begin)->next;
// 			//free(tmp->str);
// 			//free(tmp);
// 		}
// 	}
// 	return (0);
// }

// char *get_next_line(int fd)
// {
// 	size_t			bytes_read;
// 	int				i;
// 	static t_list	*begin;
// 	t_list			*tmp;
// 	char			str[BUFFER_SIZE];

// 	tmp = (t_list *)malloc(sizeof(t_list));
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, str, ))
// 		return (NULL);
// 	if (!begin)
// 		begin = tmp;
// 	bytes_read = read(fd, str, BUFFER_SIZE);
// 	tmp->str = ft_strdup(str);
// 	tmp->next = NULL;
//     while (BUFFER_SIZE <= bytes_read)
//     {
// 		i = 0;
// 		while (str[i] != '\n' && i != BUFFER_SIZE)
// 			i++;
// 		if (i == BUFFER_SIZE)
// 		{
// 			bytes_read = read(fd, str, BUFFER_SIZE);
// 			tmp = tmp->next;
// 			tmp->str = ft_strdup(str);
// 			tmp->next = NULL;
// 		}
// 		else
// 			return (create_line(&begin));
//     }
// 	return (0);
// }

// int	main(void)
// {
// 	int		fd;

//     fd = open("numbers.dict", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }