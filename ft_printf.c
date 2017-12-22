/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:22:38 by vludan            #+#    #+#             */
/*   Updated: 2017/12/22 17:31:04 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int			symb_check(char **spec, t_flg *lst)
{
	int		x;

	x = 0;
	(*spec)++;
	ft_strctn(lst);
	while (*(*spec) != 0 && *(*spec) != '%')
	{
		x = 0;
		x > 0 ? flag_check(spec, lst) : (x = flag_check(spec, lst));
		x > 0 ? min_width(spec, lst) : (x = min_width(spec, lst));
		x > 0 ? prescision(spec, lst) : (x = prescision(spec, lst));
		x > 0 ? size_check(spec, lst) : (x = size_check(spec, lst));
		if ((type_check(spec, lst) && (x = 1)) || x == 0)
			return (x);
	}
	return (x);
}

void	ft_strctn(t_flg *lst)
{
	lst->plus = 0;
	lst->sps = 0;
	lst->minus = 0;
	lst->oct = 0;
	lst->zero = 0;
	lst->m_fw = 0;
	lst->prc = -1;
	lst->type = 0;
	lst->size = 0;
	lst->sign = 0;
	lst->awct = 0;
	lst->btread = 0;
}

char		*print_operate(char **spec, va_list pt, t_flg *lst)
{
	t_or	*u;
	char	*t;

	if (!(symb_check(spec, lst)))
	{
		t = ft_memalloc(1 + 1);
		t = ft_strncpy(t, *spec, 1);
		t = alignment_mfw(lst, t);
		**spec == 0 ? 0 : (*spec += 1);
		return (t);
	}
	u = ft_memalloc(sizeof(t_or));
	type_conv_uors(lst) ? u->us = type_conv_u(lst, pt, u) :
		type_conv_s(lst, pt, u);
	t = digit_conv(lst, u);
	//printf("::::::%s\n", t);
	lst->prc > -1 ? t = presc_conv(lst, t, u) : 0;
	//printf("::::::%s\n", t);
	t = ft_format_str(lst, t, u);
	//printf("::::::%s\n", t);
	free(u);
	return (t);
}

int			print_check(char **spec, va_list pt, int x)
{
	char	*t;
	t_flg	*lst;

	while (**spec != 0)
	{
		if (**spec == '%' && **spec != 0)
		{
			lst = (t_flg*)ft_memalloc(sizeof(t_flg));
			t = print_operate(spec, pt, lst);
			lst->btread == 0 ? lst->btread = ft_strlen(t) : 0;
//			printf(":::::::::::%d\n", lst->btread);
			x += lst->btread;
			write(1, &(*t), lst->btread);
			free(lst);
		}
		while (**spec != '%' && **spec != 0)
			(write(1, &(*(*spec)++), 1) && x++);
	}
	return (x);
}

int		ft_printf(char *spec, ...)
{
	va_list		pt;
	int			x;

	x = 0;
	va_start(pt, spec);
	while (*spec != 0)
		x = print_check(&spec, pt, x);
	va_end(pt);
	return (x);
}
