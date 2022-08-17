#include <stdio.h>
#include "get_next_line.h"

char	*ft_strcpy(char *dst, char *src)
{
	size_t	i;


	if (!src || !dst)
		return (0);
	i = 0;
	while (src[i]!= '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return(dst);
}


