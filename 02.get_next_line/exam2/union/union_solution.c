#include <unistd.h>

int		main(int argc, char **argv)
{
	char	table[128];
	int		i;
	int		idx;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	i = 0;
	while (i < 128)
		table[i++] = 0;
	i = 0;
	while (argv[1][i])
	{
		idx = argv[1][i];
		if (table[idx] == 0)
		{
			table[idx] = 1;
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	i = 0;
	while (argv[2][i])
	{
		idx = argv[2][i];
		if (table[idx] == 0)
		{
			table[idx] = 1;
			write(1, &argv[2][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
}
