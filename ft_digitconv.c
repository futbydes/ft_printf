/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:21:39 by vludan            #+#    #+#             */
/*   Updated: 2017/12/21 17:52:07 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

char		*digit_conv(t_flg *flags, t_or *u)
{
	char	*t;

	if (flags->type == 'd' || flags->type == 'D' || 'i' == flags->type)
		t = ft_ib_s(u->s, 10);
	if (flags->type == 'o' || flags->type == 'O')
		t = ft_ib_u(u->us, 8);
	if (flags->type == 'u' || flags->type == 'U')
		t = ft_ib_u(u->us, 10);
	if (flags->type == 'x' || flags->type == 'X' || flags->type == 'p')
		t = ft_ib_u(u->us, 16);
	if ((flags->type == 'c' && flags->size == 3) || flags->type == 'C')
		t = ft_unicon(flags, u);
	if (flags->type == 'c' && flags->size != 3)
		t = ft_charr(u->uc);
	if ((flags->type == 's' || flags->type == 'S') && u->arr == 0 &&
			flags->awct == 0)
		t = ft_null_arr(flags, t);
	else if (flags->type == 's' && 3 != flags->size)
		t = u->arr;
	else if ((flags->type == 's' && 3 == flags->size) || flags->type == 'S')
		t = ft_unicon(flags, u);
	flags->type == '%' ? t = ft_charr('%') : 0;
	return (t);
}

char		*presc_conv(t_flg *lst, char *t, t_or *u)
{
	int		x;
	char	*p;
	char	*temp;

	*t == '-' ? lst->sign = 1 : 0;
	x = lst->prc - (int)ft_strlen(t);
//	printf(":::::%d\n", x);
	if (0 == lst->prc && u->s == 0)
		return (t = ft_memalloc(0));
	if (('s' == lst->type || 'S' == lst->type) && x < 0)
		t = ft_realloc(&t, x, lst);
	else if (x >= 0 && 's' != lst->type && 'S' != lst->type &&
			lst->type != 'c' && lst->type != 'C')
	{
//		printf("!!!:)))!!!\n");
		p = ft_realloc(&t, x, lst);
		temp = p;
		ft_memmove(p + x, p, ft_strlen(p));
		temp = ft_memset(temp, '0', (lst->sign == 1 ? x + 1 : x));
		return (temp);
	}
	return (t);
}

char		*ft_format_str(t_flg *lst, char *t, t_or *u)
{
	*t == '-' ? (lst->sign = 1) : 0;
//	printf("::::1::::::%s\n", t);
	lst->zero == 1 ? t = ft_format_zero(lst, t) : 0;
//	printf("::::1::::::%s\n", t);
	lst->sps == 1 ? t = ft_addspace(lst, t) : 0;
//	printf("::::1::::::%s\n", t);
	if (lst->sign > 0 || lst->oct == 1 || lst->type == 'p' ||
			lst->plus == 1)
		t = ft_addsign(lst, t, u);
//	printf("::::1::::::%s\n", t);
	if (lst->minus == 1 || lst->m_fw > (int)ft_strlen(t))
		t = alignment_mfw(lst, t);
	if (lst->type == 'p' || (lst->type == 'x' && lst->size != 3))
		t = ft_lowcasealph(&t);
//	printf("::::1::::::%s\n", t);
	return (t);
}

char		*ft_null_arr(t_flg *lst, char *t)
{
	t = ft_memalloc((lst->prc == -1 ? 1 : 7));
	ft_strcpy(t, "(null)");
	return (t);
}
