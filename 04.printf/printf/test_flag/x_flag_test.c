#include "ft_printf.h"
#include <stdio.h>
// cspdiuxX%

int main()
{
	unsigned int a;
	unsigned int b;
	// printf("%d\n",sizeof(long unsigned int));
	// printf("%d\n",sizeof(unsigned int));
	a = -0x1;
	a = -1;
	b = 0x422;
	printf("%x\n",a);
	printf("%x\n", a);
	printf("-----------\n");
	printf("%23x\n", b);
	printf("%-23x\n", b);
	printf("%-30.23x!\n", b);
	printf("check-----\n");
	printf("%021x\n", b);
	printf("%.12x\n", b);
	printf("%20.12x\n", b);
	printf("%-20.12x\n", b);
	printf("-------0 vs precison-----\n");
	printf("%023.12x\n",b);
	printf("%023x\n",b);
	printf("%-4.8x\n",b);
	printf("%-11.8x\n",b);
	printf("--------길이 및 채워넣기-------\n");
	unsigned int c;
	c = 0x4321512;
	printf("%1.2x\n",c);
	printf("%10.2x\n",c);
	printf("%10.12x\n",c);
	printf("%14.12x\n",c);
	unsigned int d;
	d = 0x23;
	printf("---------------\n");
	printf("%4.6x\n",d);
	printf("%6.4x\n",d);
	printf("%6.1x\n",d);
	printf("%1.4x\n",c);
	printf("---------길이_test---------\n");
	unsigned int e;
	e = 0x12345;//5개
	printf("|너비|정확도|길이|\n");
	printf("| 9 | 7 | 5 | :%9.7x\n",e);
	printf("| 9 | 3 | 5 | :%9.3x\n",e);
	printf("| 3 | 9 | 5 | :%3.9x\n",e);
	printf("| 7 | 9 | 5 | :%7.9x\n",e);
	printf("| 4 | 3 | 5 | :%4.3x\n",e);
	printf("| 3 | 4 | 5 | :%3.4x\n",e);
	printf("------------------\n");
	printf("|%11.0x|\n",e);
	printf("|%011x|\n",e);
	printf("|%011.8x|\n",e);
	printf("|%011.4x|\n",e);
	printf("|%011x|\n",e);
	printf("|%-11.4x|\n",e);
	printf("|%-11.8x|\n",e);
	printf("|%-11x|\n",e);
	// printf("%-023x\n", b);
	printf("-------** replace **--------\n");
	printf("-------** replace **--------\n");
	printf("%-*.23x!\n", 30, b);
	printf("%0*x\n", 21, b);
	printf("%.*x\n", 12, b);
	printf("---------------\n");
	// unsigned int c;
	// unsigned int d;
	// unsigned int e;
	c = 0x4321512;
	printf("%*.*x\n", 14, 12, c);
	d = 0x23;
	printf("%*.*x\n",4, 6, d);
	printf("%6.*x\n",4,d);
	e = 0x12345;//5개
	printf("|너비|정확도|길이|\n");
	printf("| 9 | 7 | 5 | :%*.*x\n",9,7,e);
	printf("| 9 | 3 | 5 | :%9.*x\n",3,e);
	printf("| 3 | 4 | 5 | :%*.4x\n",3,e);
	printf("------------------\n");
	printf("|%0*x|\n",11,e);
	printf("|%011.*x|\n",8,e);
	printf("|%0*.*x|\n", 11, 4, e);
	printf("|%-*x|\n", 11, e);
	
	//
	printf("--------UPPERCASE---------\n");
	unsigned int qwe = 0x2abcd;
	printf("|%-*X|\n", 11, qwe);
	printf("|%X|\n",qwe);
	printf("|%011.*X|\n",22,qwe);

	return (0);
}
