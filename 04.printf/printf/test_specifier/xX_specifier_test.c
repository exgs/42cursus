#include <stdio.h>
#include "ft_printf.h"
// 자료형에 대해서...

typedef struct s_struct
{
	void *data;
}	t_struct;

int main()
{
	signed short a;
	unsigned short b;
	signed int c;
	unsigned int d;
	signed long e;
	unsigned long f;
	signed long long g;
	unsigned long long h;
	signed long int i;
	unsigned long int j;
	signed long long int k;
	unsigned long long int l;
	signed char m;
	unsigned char n;
	float o;
	double p;
	long double q;
	t_struct r;
	
	void *s;
	short *t;
	int *u;
	long *v;
	long long *w;
	long long int *x;
	char *y;
	float *z;
	
	double *aa;
	long double *ab;
	char ac[10];
	t_struct *ad;
	
	void *buffer[30];
	buffer[0] = &a;buffer[5] = &f;buffer[10] = &k;buffer[15] = &p;buffer[20] = u;buffer[25] = z;
	buffer[1] = &b;buffer[6] = &g;buffer[11] = &l;buffer[16] = &q;buffer[21] = v;buffer[26] = aa;
	buffer[2] = &c;buffer[7] = &h;buffer[12] = &m;buffer[17] = &r;buffer[22] = w;buffer[27] = ab;
	buffer[3] = &d;buffer[8] = &i;buffer[13] = &n;buffer[18] = s;buffer[23] = x;buffer[28] = ac;
	buffer[4] = &e;buffer[9] = &j;buffer[14] = &o;buffer[19] = t;buffer[24] = y;buffer[29] = ad;
	int count = 30;
	for (int i = 0; i < count; i++)
	{
		// ft_printf("%p\n",buffer[i]);
		ft_printf("%x\n",buffer[i]);
		ft_printf("%X\n",buffer[i]);
		ft_printf("----------------\n");
	}
	

	return (0);
}