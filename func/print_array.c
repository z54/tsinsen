// merge to func.h

int print_array(int *x, int n)
{
	int i;
	printf("print array start\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t", x[i]);
	}
	printf("\nprint array end\n");
	return 0;
}
