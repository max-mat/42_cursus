#include <stdio.h>

int	ft_printf(const char *str, ...);

int	main(void)
{
	printf("Number is [%-15.5d] end\n", -123);

	ft_printf("Number is [%0-00-15.5d] end\n", -123);
	
	return (0);
}

