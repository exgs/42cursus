#include <unistd.h>

void ft_bzero(char *str)
{
	for (int  i = 0; str[i] != 0; i++)
	{
		str[i] = 0;
	}
}

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
	char same_buf[1024] = {0, };
	char double_buf[500] = {0, };
	// ft_bzero(same_buf);
	// ft_bzero(double_buf);
	int z = 0;
	char *str = argv[1];
	char *set = argv[2];
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	for (size_t i = 0; str[i] != 0; i++)
	{
		for (size_t j = 0; set[j] != 0; j++)
		{
			if(in_buf(str[i], set))
			{
				same_buf[z] = str[i];
				z++;
				break;
			}
		}
	}
	z = 0;
	for (size_t i = 0; str[i] != 0; i++)
	{
		if (in_buf(str[i], same_buf) && in_buf(str[i], double_buf) == 0)
		{
			write(1, str+i, 1);
			double_buf[z] = str[i];
			z++;
		}
	}
	write(1, "\n", 1);
	return (1);
}