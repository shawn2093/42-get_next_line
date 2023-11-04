#include "get_next_line.h"

int	main()
{
    // t_list	*list = NULL;
	char			*next_line;
    int fd;
    int rd;

    fd = open("aaaaaa.txt", O_RDONLY);
    rd = read(fd, next_line, 0);
	if (fd < 0 || rd < 0)
    {
        printf("%s, %d", next_line, rd);
		return (0);
    }
    printf("\n%s, %d\n", next_line, rd);
    close (fd);
}
    