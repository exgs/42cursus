/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:03:12 by yunslee           #+#    #+#             */
/*   Updated: 2020/02/29 15:03:12 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void *ft_calloc(size_t number, size_t size)
{
    char *output = malloc(number * size);
    for (size_t i = 0; i < (number * size); i++)
        output[i] = 0;
    return (output);
}
