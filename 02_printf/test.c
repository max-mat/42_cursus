int	ft_printf(const char *str, ...);

int	main(void)
{
	int n = 14;
	int *p;
	p = &n;
	ft_printf("Name is %s, age is %-10d, pointer %p, number %05i\n", "Simon", 24, p, 1);
	
	return (0);
}
