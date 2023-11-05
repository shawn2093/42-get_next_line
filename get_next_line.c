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

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

// char *get_next_line(int fd)
// {
// 	size_t			bytes_read;
// 	int				i;
// 	char			*fullstr;
// 	static char		*str;
// 	char			*tmp;

// 	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, str, 0) < 0)
// 		return (NULL);
// 	if (!str)
// 		fullstr = 0;
// 	else
// 	{
// 		tmp = ft_strchr(str, '\n');
// 		if (tmp)
// 		{
// 			i = 0;
// 			while (str[i] && str[i] != '\n')
// 				i++;
// 			fullstr = ft_substr((char const *)str, 0, (size_t) i + 1);
// 			str = tmp;
// 			return (fullstr);
// 		}
// 		tmp = ft_strdup(str);
// 	}
// 	str = (char *) malloc(BUFFER_SIZE * sizeof(char) + 1);
// 	bytes_read = BUFFER_SIZE;
//     while ((bytes_read = read(fd, str, BUFFER_SIZE)) > 0)
//     {
// 		str[bytes_read] = '\0';
// 		i = 0;
// 		// if (ft_strlen(str) > buffer)
// 		// 	str = ft_substr((char const *)str, 0, bytes_read);
// 		// printf("str after first if in while: --%s--\n", str);
// 		// printf("fullstr after first if in while: %s\n", fullstr);
// 		while (str[i] && str[i] != '\n')
// 			i++;
// 		// printf("%d\n", i);
// 		// if (bytes_read >= buffer)
// 		// 	fullstr = ft_strjoin((char const *)fullstr, (char const *)ft_substr((char const *)str, 0, (size_t) i + 1));
// 		fullstr = ft_strjoin((char const *)tmp, (char const *)ft_substr((char const *)str, 0, (size_t) i + 1));
// 		if (str[i] == '\n')
// 		{
// 			str = ft_strchr(str, '\n');
// 			return (fullstr);
// 		}
//     }
// 	if (bytes_read == 0)
// 	{
// 		free(str);
// 		str = 0;
// 	}
// 	free(str);
// 	return (fullstr);
// }

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

void clean_list(t_list **bufstr)
{
	int		i;
	int		k;
	t_list	*new;
	t_list	*tmp;
	char	*str;
	
	if (!bufstr || !*bufstr)
		return ;
	str = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	new = (t_list *) malloc(sizeof(t_list));
	if (!str || !new)
		return ;
	tmp = ft_lstlast(*bufstr);
	i = -1;
	k = 0;
	while (tmp->str[++i])
	{
		if (tmp->str[i] == '\n')
			break ;
	}
	while (tmp->str[i++])
		str[k++] = tmp->str[i];
	str[k] = 0;
	new->str = str;
	new->next = NULL;
	while (*bufstr)
	{
		tmp = (*bufstr)->next;
		free((*bufstr)->str);
		free(*bufstr);
		*bufstr = tmp;
	}
	if (*str)
		*bufstr = new;
	else
	{
		free(str);
		free(new);
	}
}

char *get_line(t_list *bufstr)
{
	char	*str;
	int		count;
	t_list	*tmp;
	int		i;
	int		len;

	count = ft_lstsize(bufstr);
	tmp = ft_lstlast(bufstr);
	i = -1;
	while (tmp->str[++i])
	{
		if (tmp->str[i] == '\n')
			break;
	}
	len = BUFFER_SIZE * (count - 1) + i;
	str = (char *) malloc(sizeof(char) * len + 1);
	len = 0;
	while (bufstr)
	{
		i = -1;
		while (bufstr->str[++i])
		{
			str[len] = bufstr->str[i];
			len++;
			if (bufstr->str[i] == '\n')
				break;
		}
		bufstr = bufstr->next;
	}
	str[len] = '\0';
	return(str);
}

int found_nl(t_list **bufstr)
{
	t_list	*tmp;
	int		i;

	tmp = *bufstr;
	while (tmp)
	{
		i = -1;
		while(tmp->str[++i])
		{
			if (tmp->str[i] == '\n')
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void create_list(int fd, t_list **bufstr)
{
	char	*str;
	size_t	buf;
	t_list	*tmp;

	while(!found_nl(bufstr))
	{
		str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return ;
		buf = read(fd, str, BUFFER_SIZE);
		if (!buf)
		{
			free(str);
			return ;
		}
		str[buf] = 0;
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp->str = str;
		tmp->next = 0;
		ft_lstadd_back(bufstr, tmp);
	}
}

char *get_next_line(int fd)
{
	char			*str;
	static t_list	*bufstr;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &str, 0) < 0)
		return (NULL);
	create_list(fd, &bufstr);
	if(bufstr == NULL)
		return (NULL);
	str = get_line(bufstr);
	clean_list(&bufstr);
	// while (bufstr)
	// {
	// 	printf("%s\n", bufstr->str);
	// 	bufstr = bufstr->next;
	// }
	return(str);
}

// int	main(void)
// {
// 	int		fd;

//     fd = open("files/multiple_line_no_nl", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%d", get_next_line(fd) == NULL);
// 	close(fd);
// 	return (0);
// }