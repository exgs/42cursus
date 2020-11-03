#include "get_next_line_cub.h"
#include <stdio.h>

int main()
{
	char **datas;
	int i = 0;
	int temp;

	datas = get_datas_linebyline("./map.cub");
	while (datas[i] != NULL)
	{
		printf("%s\n", datas[i]);
		i++;
	}
	
	if ((temp = get_free_all_linebyline(datas)) == 1)
		write(1, "free all\n", 9);
	else
		write(1, "free error\n", 11);
	return (1);
}
