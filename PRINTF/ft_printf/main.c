#include "printf.h"
#include <stdio.h>

int main()
{
	char *s;
	int i;
	int i2;

	s = "text pp";

	i = printf("%c\n, %s\n, %p\n, %i\n, %d\n, unsigned = %u\n, %x\n", 's', "asda", &s, -2147483648, -2147483648, -2147483648, -2147483648);
	printf("%d\n", i);

	i2 = ft_printf("%c\n, %s\n, %p\n, %i\n, %d\n, unsigned = %u\n, %x\n", 's', "asda", &s, -2147483648, -2147483648, -2147483648, -2147483648);
	ft_printf("%d\n", i2);

}

