/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_free()_AND_static.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:36:13 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/05 18:26:13 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	test()
{
	static int a = 0;
	a++;
	return (a);
}

int	main(void)
{
	static char *str1 = "\0";
	char *str2 = "asd";
	char *str3 = NULL;
	char *str4;
	/*static 테스트*/
	printf("%d\n", test());
	printf("%d\n", test());
	printf("%d\n", test());
	printf("%d\n", test());
	/*free함수의 에러처리*/
	// free(str1);//(X)
	// free(str2);//(X)
	// free(str3);//(O)
	// free(str4);//(O)
	return (0);
}
