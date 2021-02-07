#include <stdio.h>

int	ft_printf(const char *str, ...);

int	main(void)
{
	int n = 5;
	int *ptr1;

	int res1;
	int res2;

	char c = 'c';
	char *ptr2;

	ptr1 = &n;
	ptr2 = &c;

/*	ft_printf("[%.*s]\n", 0, "hello world");
	printf("[%*.*s]\n", 10, 0, "hello world");
*/


	res1 = printf("Number [%d] char [%c] string [%*.*s] pointer [%p] end\n", 5, 'c', -20, 0, "hello world", ptr1);

	res2 = ft_printf("Number [%d] char [%c] string [%*.*s] pointer [%p] end\n", 5, 'c', -20, 0, "hello world", ptr1);

	printf("%d\n%d\n", res1, res2);

	return (0);
}

