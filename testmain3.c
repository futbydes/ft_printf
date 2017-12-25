/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:55:05 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/12/25 14:47:18 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

/*
 * 1. Костыль деллзеро
 * 2. Чтение флоатов
 * 3. Юникод и локаль
 * 4. Скорость
 * 5. Разбить по функциям парсер и еще мб что-то
*/

int		main(void)
{
	setlocale(LC_ALL, "");
	printf("==================== UNICODE ====================\n\n");

	printf("or:%S :: %S :: %S\n", L"∞§¶•ª©˙∆˚", L"", L"Ω");
	ft_printf("ft:%S :: %S :: %S\n\n", L"∞§¶•ª©˙∆˚", L"", L"Ω");

	printf("or:%S :: %S :: %S\n", L"\0", L"ºººººººººº", L"÷≥≤µ˜∫√∫˜µ≤");
	ft_printf("ft:%S :: %S :: %S\n\n", L"\0", L"ºººººººººº", L"÷≥≤µ˜∫√∫˜µ≤");

	printf("or:%S\n", L"™£¢∞§¶øπ∂ƒ©˙∆˚¬…æªº–ß∂ƒ∞§¶•ªº–ƒ©˙∆˚…æ∂ƒ©˙∆˚¬   ¥¨dsd©˙∆˚¬…æ≈ç√∫˜µ≤≥÷®†¥¨ˆøπ“∂√∫˜µ≤≥");
	ft_printf("ft:%S\n\n", L"™£¢∞§¶øπ∂ƒ©˙∆˚¬…æªº–ß∂ƒ∞§¶•ªº–ƒ©˙∆˚…æ∂ƒ©˙∆˚¬   ¥¨dsd©˙∆˚¬…æ≈ç√∫˜µ≤≥÷®†¥¨ˆøπ“∂√∫˜µ≤≥");

	printf("or:%S :: %S :: %S\n", L"asd§", L"∂ƒ©asd", L"asdasd3324");
	ft_printf("ft:%S :: %S :: %S\n\n", L"asd§", L"∂ƒ©asd", L"asdasd3324");

	printf("or:%S :: %S :: %S\n", L"asd§\0©˙∆", L"\0∂∂ƒ©˙∆˚¬…æƒ©asd", L"asdasd3©˙\0∆˚324");
	ft_printf("ft:%S :: %S :: %S\n\n", L"asd§\0©˙∆", L"\0∂∂ƒ©˙∆˚¬…æƒ©asd", L"asdasd3©˙\0∆˚324");
}




















	//printf("or:%.f :: %.3F :: %f\n", -42.123, -1042.1234567643211234567890,\
															-123456789012345678934567890.12345678902);
	//ft_printf("ft:%.f :: %.3F :: %f\n\n", -42.123, -1042.1234567643211234567890,\
															-123456789012345678934567890.12345678902);


//	printf("or:%f :: %F :: %f\n", -1.0 / 0.0, 0.0 / 0.0, 999999999999999999999999999999999.0);
//	ft_printf("ft:%f :: %F :: %f\n\n", -1.0 / 0.0, 0.0 / 0.0, 999999999999999999999999999999999.0);
