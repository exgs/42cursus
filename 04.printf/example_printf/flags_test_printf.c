#include <stdio.h>

void flag_d_test()
{
	printf("|%*.*d|\n", 20, 10, 12345);
	printf("|%12.3d|\n", 12345);
	printf("|%12.3d|\n", 12345);
	printf("|%   .3d|\n", 12345);
	printf("|% .3d|\n", 12345);
	printf("|%.3d|\n", 12345);
	printf("|%*.d|\n", 20, 12345);
	printf("|%.*d|\n", 10, 12345);
	printf("|%.5d|\n", 12345);
	printf("|%.d|\n", 12345);
	printf("|%d|\n", 12345);
	printf("----------------------------------\n");
	printf("|%*.*%|\n", 20, 10, 12345);
	printf("|%12.3%|\n", 12345);
	printf("|%12.3%|\n", 12345);
	printf("|%   .3%|\n", 12345);
	printf("|% .3%|\n", 12345);
	printf("|%*.%|\n", 20, 12345);
	printf("|%.*%|\n", 10, 12345);
	printf("|%.5%|\n", 12345);
	printf("|%.%|\n", 12345);
	printf("|%%|\n", 12345);
	printf("----------------------------------\n");
	printf("%d\n",42);
	printf("%*d\n",42);
	printf("%.d\n",42);
	printf("%.0d\n",42);
	printf("%.1d\n",42);
	printf("%.*d\n",42);
	printf("----------------------------------\n");
	printf("%.0d\n", 0); // 출력 없음
	printf("%.0d\n", 1); // 1 출력

}

int main()
{
	printf("------------------%c 정수 flag_test-------------\n");
	flag_d_test();
	return (0);
}