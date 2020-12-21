#include <unistd.h>

int in_buf(char c, char *buf)
{
	for (size_t i = 0; buf[i] != 0; i++)
	{
		if (c == buf[i])
			return (1);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	char double_buf[1024] = {0,};
	int z = 0;
	char *s1 = argv[1];
	char *s2 = argv[2];

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	for (size_t i = 0; s1[i] != 0; i++)
	{
		if (in_buf(s1[i], double_buf) == 0)
		{
			write(1, &s1[i], 1);
			double_buf[z] = s1[i];
			z++;
		}
	}

	for (size_t i = 0; s2[i] != 0; i++)
	{
		if (in_buf(s2[i], double_buf) == 0)
		{
			write(1, &s2[i], 1);
			double_buf[z] = s2[i];
			z++;
		}
	}
	write(1, "\n", 1);
	return (1);
}