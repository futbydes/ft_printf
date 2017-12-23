/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:55:42 by vludan            #+#    #+#             */
/*   Updated: 2017/12/23 13:09:05 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

char			*ft_realloc(char **arr, int size, t_or *u)
{
	char		*new;
	int			len;

//	printf("::realloc:addr:::%p\n", *arr);
//	printf("::realloc:addr:::%s\n", *arr);
	if (!arr)
		return (*arr);
	len = ft_strlen(*arr);
	new = ft_memalloc((len + size) + 1);
	new = ft_memcpy(new, *arr, len + size);
	if (&(u->arr) != arr)
		free(*arr);
	return (new);
}

char			*ft_unicon(t_flg *lst, t_or *u)
{
	char		*t;
	char		*temp;
	int			x;

	if (lst->type == 'S' || lst->type == 's')
	{
		t = ft_memalloc(1);
		while (*lst->awct)
		{
			u->wct = ft_unicon_conv(*(lst->awct)++);
			x = 1 + ((unsigned int)u->wct > 255) + ((unsigned int)u->wct >
					65535) + ((unsigned int)u->wct > 16777215);
			if (MB_CUR_MAX < x)
			{
				t = ft_realloc(&(t), x, u);
				return (t);
			}
			t = ft_realloc(&(t), x, u);
			if ((temp = ft_unicon_arr(u, lst)) && (*temp == 0))
				return (t);
			ft_memcpy(t + ft_strlen(t), temp, x);
		}
	}
	if (lst->type == 'C' || lst->type == 'c')
	{
		u->wct = ft_unicon_conv(u->wct);
		t = ft_unicon_arr(u, lst);
	}
	return (t);
}

char			*ft_unicon_arr(t_or *u, t_flg *lst)
{
	char		*arr;
	int			x;
	int			y;

	x = 1 + ((unsigned int)u->wct > 255) + ((unsigned int)u->wct > 65535) +
		((unsigned int)u->wct > 16777215);
	y = 0;
	MB_CUR_MAX < x ? x = MB_CUR_MAX : 0;
	arr = ft_memalloc(x);
	if (lst->prc != -1)
	{
		lst->prc -= x;
		if (lst->prc < 0)
			return (arr);
	}
	while (x--)
		arr[y++] = u->byte[x];
	return (arr);
}

wchar_t			ft_unicon_conv(wchar_t c)
{
	wchar_t		res;

	if ((int)c <= 127)
		return (res = c);
	else if ((int)c <= 2047 && MB_CUR_MAX >= 2)
		return (res = ((c & 0x3F) | 0xC080) | ((c & 0x7C0) << 2));
	else if ((int)c <= 65535 && MB_CUR_MAX >= 3)
		return (res = (((c & 0x3F) | 0xE08080) | ((c & 0xFC0) << 2)) |
				((c & 0xF000) << 4));
	else if (MB_CUR_MAX >= 4)
		return (res = ((((c & 0x3F) | 0xF0808080) | ((c & 0xFC0) << 2)) |
					((c & 0x3F000) << 4) | ((c & 0xFC0000) << 3)));
	else
		return (c);
}
