#include "get_next_line.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chr;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == chr)
			return (&str[i]);
		i++;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		else
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst && new)
	{
		if (*lst)
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new;
		}
		else
			*lst = new;
	}
}

t_list	*ft_lstnew(char *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (0);
	ptr->str = content;
	ptr->next = NULL;
	return (ptr);
}

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

char *get_next_line(int fd)
{
    //t_list	**begin;
	t_list	*tmp;
	size_t	bytes_read;
	size_t     buffer;
	char	*str;
	char	*fullstr;

    buffer = 1;
	str = (char *) malloc(buffer * sizeof(char));
	tmp = (t_list *) malloc(sizeof(t_list));
	bytes_read = buffer;
	fullstr = "";
    while (buffer <= bytes_read)
    {
	    bytes_read = read(fd, str, buffer);
		fullstr = ft_strjoin((char const *)fullstr, (char const *)str);
		if (ft_memchr((const void *)str, '\n', bytes_read))
			return (fullstr);
		// tmp = ft_lstnew(str);
		// ft_lstadd_back(begin, tmp);
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