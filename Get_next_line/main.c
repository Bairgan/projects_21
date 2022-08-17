#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	char	*line = NULL;
// 	int		fd;
// 	int		gnl;
// 	int		i;

// 	i = 1;
// 	printf("argc=%d, argv[0]=%s\n", argc, argv[0]);
// 	if (argc > 1)
// 	{
// 		gnl = 1;
// 		while (gnl > 0)
// 		{
// 			fd = 0;
// 			gnl = get_next_line(fd, &line);
// 			printf("%d. line=|%s|, fd=%d, gnl=|%d|\n\n", i, line, fd, gnl);
// 			i++;
// 		}

// 	}
// 	else
// 	{
// 		gnl = 1;
// 		fd = open("fail.txt", O_RDONLY);
// 		while (gnl > 0)
// 		{
// 			gnl = get_next_line(fd, &line);
// 			printf("%d. line=|%s|, fd=%d, gnl=|%d|\n\n", i++, line, fd, gnl);
// 		}
// 		return (0);
// 	}
// }
//clang -g -Wall -Werror -Wextra main.c get_next_line.c get_next_line.h get_next_line_utils.c -D BUFFER_SIZE=1 && ./a.out

// int	main(void)
// {
// 	char	*line;
// 	int		fd;
// 	int n = 0;
// 	fd = open("fail.txt", O_RDONLY);
// 	while ((n = get_next_line(0, &line) > 0))
// 	{
// 		printf("%s (n = %d)\n",line, n);
// 		//free(line);
// 	}
// 	printf("%s (n = %d)\n",line, n);


// }

int	main(void)
{
	char	*line;
	int		fd;
	int 	n = 0;

	fd = open("line.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
	{
		n++;
		printf("(%d)%s", n, line);
		ft_free(&line);
	}
}
