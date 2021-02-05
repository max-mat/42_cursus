#include <stdio.h>

int	ft_printf(const char *str, ...);

int	main(void)
{
	int n = 5;
	int *ptr1;

	char c = 'c';
	char *ptr2;

	ptr1 = &n;
	ptr2 = &c;

	printf("Number is [%% %% %d] end\n", 5);

	ft_printf("Number is [%% %% %d] end\n", 5);

	return (0);
}

