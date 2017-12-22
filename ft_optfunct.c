/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:55:42 by vludan            #+#    #+#             */
/*   Updated: 2017/12/22 15:12:17 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

char			*ft_realloc(char **arr, int size, t_flg *lst)
{
	char		*new;
	int			len;

	if (!arr || !size)
		return (*arr);
	len = ft_strlen(*arr);
	new = ft_memalloc((len + size) + 1);
	new = ft_memcpy(new, *arr, len + size);
	if (*arr != 0 && lst->type != 's' && lst->type != 'S')
		free(*arr);
	return (new);
}

char			*ft_unicon(t_flg *lst,  t_or *u)
{
	char		*t;
	char		*temp;

	if (lst->type == 'S' || lst->type == 's')
	{
		t = ft_memalloc(1);
		while (*lst->awct)
		{
			u->wct = ft_unicon_conv(*(lst->awct)++);
			t = ft_realloc(&(t), 4, lst);
			temp = ft_unicon_arr(u);
			ft_memcpy(t + ft_strlen(t), temp, 4);
		}
	} 
	if (lst->type == 'C' || lst->type == 'c')
	{
		u->wct = ft_unicon_conv(u->wct);
		t = ft_unicon_arr(u);
	}
	return (t);
}

char		*ft_unicon_arr(t_or *u)
{
	char	*arr;
	int		x;
	int		y;


	x = 1 + ((unsigned int)u->wct > 255) + ((unsigned int)u->wct > 65535) +
		((unsigned int)u->wct > 16777215);
	y = 0;
	arr = ft_memalloc(x);
	while (x--)
		arr[y++] = u->byte[x];
	return (arr);
}

wchar_t		ft_unicon_conv(wchar_t c)
{
	wchar_t res;

	if ((int)c <= 127)
		return (res = c);
	else if ((int)c <= 2047)
		return (res = ((c & 0x3F) | 0xC080) | ((c & 0x7C0) << 2));
	else if ((int)c <= 65535)
		return (res = (((c & 0x3F) | 0xE08080) | ((c & 0xFC0) << 2)) |
				((c & 0xF000) << 4));
	else
		return (res = ((((c & 0x3F) | 0xF0808080) | ((c & 0xFC0) << 2)) |
					((c & 0x3F000) << 4) | ((c & 0xFC0000) << 3)));
}
