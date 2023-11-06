/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:59:29 by long              #+#    #+#             */
/*   Updated: 2023/11/07 01:36:42 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
// 		// 	fullstr = ft_strjoin((char const *)fullstr,
//					(char const *)ft_substr((char const *)str, 0, (size_t) i
//						+ 1));
// 		fullstr = ft_strjoin((char const *)tmp,
//				(char const *)ft_substr((char const *)str, 0, (size_t) i + 1));
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

char	*fill_letters(t_list *bufstr, int len)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	len = 0;
	while (bufstr)
	{
		i = -1;
		while (bufstr->str[++i])
		{
			str[len] = bufstr->str[i];
			len++;
			if (bufstr->str[i] == '\n')
				break ;
		}
		bufstr = bufstr->next;
	}
	str[len] = '\0';
	return (str);
}

char	*get_line(t_list *bufstr)
{
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
			break ;
	}
	len = BUFFER_SIZE * (count - 1) + i;
	return (fill_letters(bufstr, len));
}

int	found_nl(t_list **bufstr)
{
	t_list	*tmp;
	int		i;

	tmp = *bufstr;
	while (tmp)
	{
		i = -1;
		while (tmp->str[++i])
		{
			if (tmp->str[i] == '\n')
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	create_list(int fd, t_list **bufstr)
{
	char	*str;
	size_t	buf;
	t_list	*tmp;

	while (!found_nl(bufstr))
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

char	*get_next_line(int fd)
{
	char			*str;
	static t_list	*bufstr;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &str, 0) < 0)
		return (NULL);
	create_list(fd, &bufstr);
	if (bufstr == NULL)
		return (NULL);
	str = get_line(bufstr);
	clean_list(&bufstr);
	return (str);
}

// int	main(void)
// {
// 	int		fd;

//     fd = open("1-brouette.txt", O_RDONLY);
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
