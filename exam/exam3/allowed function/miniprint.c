#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FALSE 0
#define TRUE 1

#define SUCCESS 0
#define ERROR 1

typedef struct s_background
{
	int width;
	int height;
	char c;
}t_background;


typedef struct s_circle
{
	float x, y, r;
	char f;
	char c;
}t_circle;


int ft_strlen(char *str)
{
	if (str == NULL)
		return (-1);
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
	return ;
}

int exit_free(FILE *file, int valid)
{
	fclose(file);
	if (valid == ERROR)
		return (ERROR);
	else if (valid == SUCCESS)
		return (SUCCESS);
	return (SUCCESS);
}

int error_exam03(int argc, char *argv[], FILE **file)
{
	if (argc != 2)
	{
		ft_putstr("Error: argument\n");
		return (ERROR);
	}
	// if (NULL == (*file = fopen("./exam03/minipaint", "r")))
	// if (NULL == (*file = fopen("minipaint2", "r")))
	if (NULL == (*file = fopen(argv[1], "r")))
	{
		ft_putstr("Error: Operation file corrupted\n");
		return (exit_free(*file, ERROR));
	}
	return (SUCCESS);
}

void change_buf(char **buf, t_circle circle)
{
	int x = 0;
	int y = 0;
	while (buf[y])
	{
		x = 0;
		while (buf[y][x])
		{
			if (sqrtf(powf((float)x - circle.x, 2) + powf((float)y - circle.y, 2)) >= circle.r)
			{
				x++;
				continue;
			}
			else if ((sqrtf(powf((float)x - circle.x, 2) + powf((float)y - circle.y, 2)) > (circle.r - 1)) &&
						(sqrtf(powf((float)x - circle.x, 2) + powf((float)y - circle.y, 2)) < circle.r))
			{
				buf[y][x] = circle.c;
			}
			else if (sqrtf(powf(x - circle.x, 2) + powf(y - circle.y, 2)) <= (circle.r - 1) && circle.f == 'C')
			{
				buf[y][x] = circle.c;
			}
			x++;
		}
		y++;
	}
}


int read_scanf(FILE *file, char ***buf)
{
	t_background background;
	t_circle circle;
	int temp;
	if (3 != (temp = fscanf(file, "%d %d %c\n", &background.width, &background.height, &background.c)))
	{
		// printf("===%d\n", temp);
		// ft_putstr("Error: Operation file corrupted\n");
		return (exit_free(file, ERROR));
	}
	// printf("%d %d %c\n", background.width, background.height, background.c);
	*buf = malloc(sizeof(char *) * ((int)background.height + 1));
	for (size_t i = 0; i < background.height; i++)
	{
		(*buf)[i] = malloc(sizeof(char) * (background.width + 1));
		memset((*buf)[i], background.c, background.width);
		(*buf)[i][background.width] = 0;
	}
	(*buf)[(int)background.height] = NULL;
	
	while ((-1 != (temp = fscanf(file, "%c %f %f %f %c\n", &circle.f, &circle.x, &circle.y, &circle.r, &circle.c))))
	{
		// printf("-\n");
		// printf("%d\n", temp);
		if (5 != temp || circle.c <= 31 || circle.c >= 127 || (circle.f != 'c' && circle.f!= 'C') ||
				background.width < 1 || background.height < 1)
		{
			// printf("--\n");
			// printf("%d\n", temp);
			// ft_putstr("Error: Operation file corrupted\n");
			return (exit_free(file, ERROR));
		}
		//써주는 함수
		change_buf(*buf, circle);
		// printf("%c %f %f %f %c\n", circle.f, circle.x, circle.y, circle.r, circle.c);
	}
	// printf("=========\n");
	// printf("%d\n", temp);
	return (exit_free(file, SUCCESS));
}

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char **buf;
	if (error_exam03(argc, argv, &file) == ERROR)
		return (ERROR);
	if (read_scanf(file, &buf) == ERROR)
		return (ERROR);
	for (size_t i = 0; i < buf[i]; i++)
	{
		ft_putstr(buf[i]);
		write(1, "\n", 1);
	}
	return (SUCCESS);
}