/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ib_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:34:56 by vludan            #+#    #+#             */
/*   Updated: 2017/12/09 11:36:32 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t			num_len(uintmax_t num, uintmax_t base)
{
	uintmax_t				x;

	x = 0;
	(num <= 0 && base == 10) ? x++ : 0;
	while (num)
	{
		num = num / base;
		x++;
	}
	return (x);
}

char			*ft_ib_u(uintmax_t num, uintmax_t base)
{
	char		*arr;
	char		*temp;
	uintmax_t	x;

	x = num_len(num, base);
	arr = (char*)malloc(sizeof(char) * x + 1);
	temp = arr;
	num == 0 ? arr[x--] = '0' : 0;
	arr[x--] = 0;
	if (num > 0)
		while (num)
		{
			arr[x--] = (num % base) + (num % base > 9 ? 'A' - 10 : '0');
			num = num / base;
		}
	return (temp);
}
