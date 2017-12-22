/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:22:32 by vludan            #+#    #+#             */
/*   Updated: 2017/12/22 11:08:35 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

typedef struct 	s_flags
{
	char 		plus;
	char 		sps;
	char 		minus;
	char 		oct;
	char 		zero;
	int			m_fw;
	int			prc;
	char		type;
	int			size;
	char		sign;
	wchar_t		*awct;
	int			btread;
}				t_flg;

typedef union		u_uors
{
	intmax_t		s;
	uintmax_t		us;
	unsigned char	uc;
	char			*arr;
	char			c;
	wchar_t			wct;
	unsigned char	byte[5];
}					t_or;

enum 	e_size_mod{hh = 1, h, l, ll, j, z};

int		ft_printf(char *spec, ...);
int		print_check(char **spec, va_list pt, int x);
char	*print_operate(char **spec, va_list pt, t_flg *lst);
int		symb_check(char **spec, t_flg *lst);
int		flag_check(char **spec, t_flg *flags);
int		min_width(char **spec, t_flg *flags);
int		prescision(char **spec, t_flg *flags);
void	size_check_hl(char **spec, t_flg *flags);
void	size_check_jz(char **spec, t_flg *flags);
int		size_check(char **spec, t_flg *flags);
int		type_check(char **spec, t_flg *flags);
uintmax_t	type_conv_u(t_flg *flags, va_list pt, t_or *u);
void	type_conv_s(t_flg *flags, va_list pt, t_or *u);
int		type_conv_uors(t_flg *f);
char	*digit_conv(t_flg *flags, t_or *u);
char	*ft_ib_u(uintmax_t num, uintmax_t base);
char	*ft_ib_s(intmax_t num, intmax_t base);
char	*ft_lowcasealph(char **t);
char	*ft_charr(unsigned char t);
int		type_conv_sflgs(t_flg *f);
char	*presc_conv(t_flg *flags, char *t, t_or *u);
int		presc_flgs(t_flg *flags);
void	ft_strctn(t_flg *lst);
char	*ft_realloc(char **arr, int size, t_flg *lst);
char	*ft_format_str(t_flg *lst, char *t, t_or *u);
char	*ft_addspace(t_flg *lst, char *t);
char	*ft_format_zero(t_flg *lst, char *t);
char	*ft_addsign(t_flg *lst, char *t, t_or *u);
int		ft_addsign_condition(t_flg *lst, char *t);
char	*alignment_mfw(t_flg *lst, char *t);
char	*ft_unicon(t_flg *lst, t_or *u);
wchar_t		ft_unicon_conv(wchar_t c);
char        *ft_unicon_arr(t_or *u);
char	*ft_null_arr(t_flg *lst, char *t);
int		ft_atoi(const char *str);
void	*ft_memalloc(size_t size);
void    *ft_memcpy(void *dst, const void *src, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t len);
void    *ft_memset(void *b, int c, size_t len);
char	*ft_strcpy(char *dst, const char *src);
size_t  ft_strlen(const char *s);
char    *ft_strncpy(char *dst, const char *src, size_t len);

#endif
