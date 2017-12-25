/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:55:42 by vludan            #+#    #+#             */
/*   Updated: 2017/12/25 18:05:50 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

char			*ft_realloc(char **arr, int size, t_or *u)
{
	char		*new;
	int			len;

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
		t = ft_memalloc(0);
		while (*lst->awct)
		{
			u->wct = ft_unicon_conv(*(lst->awct)++, lst);
			x = 1 + ((unsigned int)u->wct > 255) + ((unsigned int)u->wct >
					65535) + ((unsigned int)u->wct > 16777215);
			t = ft_realloc(&(t), x, u);
			if ((temp = ft_unicon_arr(u, lst)) && *temp == 0)
				return (t);
			ft_memcpy(t + ft_strlen(t), temp, x);
			free(temp);
		}
	}
	if (lst->type == 'C' || lst->type == 'c')
	{
		if (MB_CUR_MAX == 1)
			u->wct = (char)ft_unicon_conv(u->wct, lst);
		else
			u->wct = ft_unicon_conv(u->wct, lst);
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
	if (lst->type == 'C' || lst->type == 'c')
		MB_CUR_MAX == 1 ? x = 1 : 0;
	arr = ft_memalloc(x);
	if ((lst->prc > -1 && (lst->type == 's' || lst->type == 'S')) ||
		   	((lst->prc > 0 && lst->m_fw <= lst->prc) && (lst->type == 'C' ||
				lst->type == 'c')))
	{
		lst->prc -= x;
		if (lst->prc < 0)
			return (arr);
	}
	 while (x--)
		arr[y++] = u->byte[x];
	return (arr);
}

wchar_t			ft_unicon_conv(wchar_t c, t_flg *lst)
{
	wchar_t		res;

	if (MB_CUR_MAX > 1 || (lst->type == 'S' || lst->type == 's'))
	{
	if ((int)c <= 127)
		return (res = (char)c);
	else if ((int)c <= 2047)
		return (res = ((c & 0x3F) | 0xC080) | ((c & 0x7C0) << 2));
	else if ((int)c <= 65535)
		return (res = (((c & 0x3F) | 0xE08080) | ((c & 0xFC0) << 2)) |
				((c & 0xF000) << 4));
	else if ((int)c >= 65536)
		return (res = ((((c & 0x3F) | 0xF0808080) | ((c & 0xFC0) << 2)) |
					((c & 0x3F000) << 4) | ((c & 0xFC0000) << 3)));
	}
	else
		res = (char)c;
	return (res);
}
