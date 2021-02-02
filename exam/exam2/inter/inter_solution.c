#include <unistd.h>

int		main(int argc, char **argv)
{
	char	table[128];
	int		i;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return 0;
	}
	i = 0;
	while (i < 128)
		table[i++] = 0;
	i = 0;
	while (argv[2][i])
	{
		table[(int)argv[2][i]] = 1;
		i++;
	}
	i = 0;
	while (argv[1][i])
	{
		if (table[(int)argv[1][i]] == 1)
		{
			table[(int)argv[1][i]] = 0;
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
}
