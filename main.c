/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vludan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:16:24 by vludan            #+#    #+#             */
/*   Updated: 2017/12/25 14:19:46 by vludan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <locale.h>
#include <limits.h>

int		main(void)
{
	int		x = 42545414;
	char	c = 0;
	wchar_t	wc = 0;
	wchar_t	*awc = 0;

//	setlocale(LC_ALL, "");
	
	printf("==TEST_1==\n");
	printf("%d\n", x);
	ft_printf("%d\n", x);

	printf("==TEST_2==\n");
	printf("%hhD\n", 346734623872);
	ft_printf("%hhD\n", 346734623872);

	printf("==TEST_3==\n");
	printf("%llhhd\n", x);
	ft_printf("%llhhd\n", x);

	printf("==TEST_4==\n");
	printf("%llhhX\n", 500);
	ft_printf("%llhhX\n", 500);

	printf("==TEST_5==\n");
	printf("%llhhx\n", 312321412);
	ft_printf("%llhhx\n", 312321412);

	printf("==TEST_6==\n");
	printf("%d\n", -312321412);
	ft_printf("%d\n", -312321412);

	printf("==TEST_7==\n");
	printf("%ld\n", -312321412);
	ft_printf("%ld\n", -312321412);

	printf("==TEST_8==\n");
	printf("%hho\n", 312321412);
	ft_printf("%hho\n", 312321412);

	printf("==TEST_9==\n");
	printf("%hhU\n", -312321412);
	ft_printf("%hhU\n", -312321412);

	printf("==TEST_10==\n");
	printf("%u\n", -2312321412);
	ft_printf("%u\n", -2312321412);

	printf("==TEST_11==\n");
	printf("%llhhU\n", 312321412);
	ft_printf("%llhhU\n", 312321412);

	printf("==TEST_12==\n");
	printf("%hhllc\n", 312);
	ft_printf("%hhllc\n", 312);

	printf("==TEST_13==\n");
	printf("%c\n", 69);
	ft_printf("%c\n", 69);

	printf("==TEST_14==\n");
	printf("%s\n", "UNIT.FACT.42 tst0");
	ft_printf("%s\n", "UNIT.FACT.42 tst0");

	printf("==TEST_15==\n");
	printf("%p\n", x);
	ft_printf("%p\n", x);

	printf("==TEST_16==\n");
	printf("%hhD\n", x);
	ft_printf("%hhD\n", x);

	printf("==TEST_17==\n");
	printf("%hhi\n", x);
	ft_printf("%hhi\n", x);

	printf("==TEST_18==\n");
	printf("%+.20d\n", -43243234);
	ft_printf("%+.20d\n", -43243234);

	printf("==TEST_19==\n");
	printf("%.20d\n", -43243234);
	ft_printf("%.20d\n", -43243234);

	printf("==TEST_20==\n");
	printf("%-045.20d\n", -43243234); 
	ft_printf("%-045.20d\n", -43243234);

	printf("==TEST_21==\n");
	printf("%25 .20d\n", -43243234);
	ft_printf("%25 .20d\n", -43243234);

	printf("==TEST_21.1==\n");
	printf("%25.20d\n", -43243234);
	ft_printf("%25.20d\n", -43243234);

	printf("==TEST_22==\n");
	printf("%hh 72.3d\n", -43243234);
	ft_printf("%hh 72.3d\n", -43243234);

	printf("==TEST_23==\n");
	printf("%20d\n", -43243234);
	ft_printf("%20d\n", -43243234);

	printf("==TEST_24==\n");
	printf("%.20d\n", 43243234);
	ft_printf("%.20d\n", 43243234);

	printf("==TEST_25==\n");
	printf("%.d\n", 43243234);
	ft_printf("%.d\n", 43243234);

	printf("==TEST_26==\n");
	printf("%.x\n", 0);
	ft_printf("%.x\n", 0);

	printf("==TEST_27==\n");
	printf("%.4s\n", "UNITFACTORY");
	ft_printf("%.4s\n", "UNITFACTORY");

	printf("==TEST_28==\n");
	printf("%.90s\n", "UNITFACTORY");
	ft_printf("%.90s\n", "UNITFACTORY");

	printf("==TEST_29==\n");
	printf("%.8p\n", 746234);
	ft_printf("%.8p\n", 746234);

	printf("==TEST_30==\n");
	printf("%.8d\n", 746234);
	ft_printf("%.8d\n", 746234);

	printf("==TEST_31==\n");
	printf("%.8X\n", 746234);
	ft_printf("%.8X\n", 746234);

	printf("==TEST_32==\n");
	printf("%.8hhd\n", 321746234);
	ft_printf("%.8hhd\n", 321746234);

	printf("==TEST_33==\n");
	printf("%129.80d\n", 438758743);
	ft_printf("%129.80d\n", 438758743);

	printf("==TEST_34==\n");
	printf("%+-4.8d\n", 74623);
	ft_printf("%+-4.8d\n", 74623);

	printf("==TEST_36==\n");
	printf("%#.34x\n", 43232);
	ft_printf("%#.34x\n", 43232);

	printf("==TEST_37==\n");
	printf("%.d\n", 0);
	ft_printf("%.d\n", 0);

	printf("==TEST_38==\n");
	printf("%+60.40p\n", 42343);
	ft_printf("%+60.40p\n", 42343);

	printf("==TEST_39==\n");
	printf("%040.30p\n", 42343);
	ft_printf("%040.30p\n", 42343);

	printf("==TEST_40==\n");
	printf("%.p\n", 0);
	ft_printf("%.p\n", 0);

	printf("==TEST_41==\n");
	printf("%p\n", 0);
	ft_printf("%p\n", 0);

	printf("==TEST_42==\n");
	printf("%.5d\n", 12345);
	ft_printf("%.5d\n", 12345);

	printf("==TEST_43==\n");
	printf("%.0o\n", 12345);
	ft_printf("%.0o\n", 12345);

	printf("==TEST_44==\n");
	printf("%.s\n", "ddsd");
	ft_printf("%.s\n", "ddsd");

	printf("==TEST_45==\n");
	printf("% d\n", 432);
	ft_printf("% d\n", 432);

	printf("==TEST_46==\n");
	printf("% x\n", 432);
	ft_printf("% x\n", 432);

	printf("==TEST_47==\n");
	printf("% d\n", -432);
	ft_printf("% d\n", -432);

	printf("==TEST_48==\n");
	printf("%+U\n", 432);
	ft_printf("%+U\n", 432);

	printf("==TEST_49==\n");
	x = printf("%+040d\n", 34876432);
	printf("%d\n", x);
	x = ft_printf("%+040d\n", 34876432);
	printf("%d\n", x);

	printf("==TEST_49.1==\n");
	x = printf("%+040d\n", -34876432);
	printf("%d\n", x);
	x = ft_printf("%+040d\n", -34876432);
	printf("%d\n", x);

	printf("==TEST_50==\n");
	printf("%+040.d\n", 34876432);
	ft_printf("%+040.d\n", 34876432);

	printf("==TEST_51==\n");
	printf("%-040d\n", -34876432);
	ft_printf("%-040d\n", -34876432);

	printf("==TEST_52==\n");
	printf("%030d\n", 34876432);
	ft_printf("%030d\n", 34876432);

	printf("==TEST_53==\n");
	printf("%030d\n", -34876432);
	ft_printf("%030d\n", -34876432); 

	printf("==TEST_54==\n");
	printf("%#o\n", -34876432);
	ft_printf("%#o\n", -34876432); 

	printf("==TEST_55==\n");
	printf("%012.6s\n", "fdfdfd");
	ft_printf("%012.6s\n", "fdfdfd");

	printf("==TEST_56==\n");
	printf("%012.6d\n", "fdfdfd");
	ft_printf("%012.6d\n", "fdfdfd");

	printf("==TEST_57==\n");
	printf("%0p\n", x); 
	ft_printf("%0p\n", x);
	printf("%032.32p\n", x); 
	ft_printf("%032.32p\n", x); 

	printf("==TEST_58==\n");
	printf("%7.c\n", 69);
	ft_printf("%7.c\n", 69);

	printf("==TEST_59==\n");
	printf("asd%7.c\n", 69);
	ft_printf("asd%7.c\n", 69);

	printf("==TEST_59.1==\n");
	printf("asd%-7.2cfjlsdk\n", 69);
	ft_printf("asd%-7.2cfjlsdk\n", 69);

	printf("==TEST_60.1==\n");
	x = printf("asd%6.21cfjlsdk\n", 69);
	ft_printf("asd%6.21cfjlsdk\n", 69);

	printf("==TEST_61==\n");
	printf("hel%-+0.13slo\n", "moto");
	ft_printf("hel%-+0.13slo\n", "moto");

	printf("==TEST_62==\n");
	printf("hel%-4.3slo\n", "moto");
	ft_printf("hel%-4.3slo\n", "moto");

	printf("==TEST_62.1==\n");
	printf("hel%4.3slo\n", "moto");
	ft_printf("hel%4.3slo\n", "moto");

	printf("==TEST_63==\n");
	x = printf("raiser%dsf423%s234al1%1+#x\n", 24, "boom", -423423);
	ft_printf("raiser%dsf423%s234al1%1+#x\n", 24, "boom", -423423);

	printf("==TEST_64==\n");
	printf("raiser%dsf423\n", 24, "boom", -423423);
	ft_printf("raiser%dsf423\n", 24, "boom", -423423);

	printf("==TEST_65==\n");
	printf("sf423%s234al1%1+#x\n", "boom", -423423);
	ft_printf("sf423%s234al1%1+#x\n", "boom", -423423);

	printf("==TEST_66==\n");
	printf("%#+x\n", "boom");
	ft_printf("%#+x\n", "boom");

	printf("==TEST_67==\n");
	x = printf("%1+#.s\n", "boom");
	x = ft_printf("%1+#.s\n", "boom");

	printf("==TEST_68==\n");
	printf("%5s\n", "boom");
	ft_printf("%5s\n", "boom");

	printf("==TEST_69==\n");
	x = printf("%.60c", 's');
	printf("%d\n", x);
	x = ft_printf("%.60c", 's');
	printf("%d\n", x);

	printf("==TEST_70==\n");
	printf("%5.70s\n", "boom");
	ft_printf("%5.70s\n", "boom");

	printf("==TEST_71==\n");
	printf("%.60c\n", "dsdadsad");
	ft_printf("%.60c\n", "dsdadsad");

	printf("==TEST_73==\n");
	printf("dsad%.dasdl60c\nsda", "dsdadsad");
	ft_printf("dsad%.dasdl60c\nsda", "dsdadsad");

	printf("==TEST_74==\n");
	printf("%0p\n", 432423423423);
	ft_printf("%0p\n", 432423423423);

	printf("==TEST_75==\n");
	printf("%.p\n", 0);
	ft_printf("%.p\n", 0);

	printf("==TEST_75.1==\n");
	printf("%.x\n", 0);
	ft_printf("%.x\n", 0);

	printf("==TEST_76==\n");
	c = 0;
	x = printf("%c", 0);
	printf("%d\n", x);
	x = ft_printf("%c", 0);
	ft_printf("%d\n", x);

	printf("==TEST_77==\n");
	wc = L'𐤃';
	x = printf("%C", wc);
	printf("%d\n", x);
	x = ft_printf("%lc", wc);
	ft_printf("%d\n", x);

	printf("==TEST_78==\n");
	wc = L'𐤃';
	x = printf("1111%11c1111", 0);
	printf("%d\n", x);
	x = ft_printf("1111%11c1111", 0);
	ft_printf("%d\n", x);

	printf("==TEST_79==\n");
	awc = L"𐤃𐤃𐤃𐤃LSA𐤃";
	x = printf("%S", awc);
	printf("%d\n", x);
	x = ft_printf("%S", awc);
	printf("%d\n", x);

	printf("==TEST_80==\n");
	wc = L'𐤃';
	x = printf("%011.1s", 0); 
	printf("%d\n", x);
	x = ft_printf("%011.1s", 0);
	printf("%d\n", x);

	printf("==TEST_80==\n");
	x = printf("%.s", 0);
	printf("%d\n", x);
	x = ft_printf("%.s", 0);
	printf("%d\n", x);

	printf("==TEST_81==\n");
	x = printf("1111%0.c1111", 0);
	printf("%d\n", x);
	x = ft_printf("1111%0.c1111", 0);
	ft_printf("%d\n", x);

	printf("==TEST_82==\n");
	printf("%012.5s\n", "fdfdfd"); 
	ft_printf("%012.5s\n", "fdfdfd");

	printf("==TEST_83==\n");
	x = printf("%s\n", ""); 
	printf("%d\n", x);
	x = ft_printf("%s\n", ""); 
	ft_printf("%d\n", x);

	printf("==TEST_84==\n");
	x = printf("%1dhjsdh%d.s\n", 0); 
	printf("%d\n", x);
	x = ft_printf("%1dhjsdh%d.s\n", 0); 
	ft_printf("%d\n", x);

	printf("==TEST_85==\n");
	x = printf("%");
	printf("%d\n", x);
	x = ft_printf("%");
	printf("%d\n", x);

	printf("==TEST_86==\n");
	x = printf("{% %}");
	printf("%d\n", x);
	x = ft_printf("{% %}");
	printf("%d\n", x);

	printf("==TEST_87==\n");
	x = printf("{%%%%%%%%%}");
	printf("%d\n", x);
	x = ft_printf("{%%%%%%%%%}");
	printf("%d\n", x);

	printf("==TEST_88==\n");
	x = printf("{% 19ZZZZZZ %}");
	printf("%d\n", x);
	x = ft_printf("{% 19ZZZZZZ %}");
	printf("%d\n", x); 

	printf("==TEST_90==\n");
	x = printf("%#X", 0);
	printf("%d\n", x); 
	x = ft_printf("%#X", 0);
	printf("%d\n", x); 

	printf("==TEST_91==\n");
	x = printf("%#x", 109);
	printf("%d\n", x); 
	x = ft_printf("%#x", 109);
	printf("%d\n", x); 

	printf("==TEST_92==\n");
	x = printf("%#08o", 4212);
	printf("%d\n", x); 
	x = ft_printf("%#08o", 4212);
	printf("%d\n", x); 

	printf("==TEST_92.1==\n");
	x = printf("%#08x", 4212);
	printf("%d\n", x); 
	x = ft_printf("%#08x", 4212);
	printf("%d\n", x); 

	printf("==TEST_92.2==\n");
	x = printf("%010x", 422);
	printf("%d\n", x); 
	x = ft_printf("%010x", 422);
	printf("%d\n", x); 

	printf("==TEST_93==\n");
	x = printf("%#.x", 0);
	printf("%d\n", x); 
	x = ft_printf("%#.x", 0);
	printf("%d\n", x); 

	printf("==TEST_94==\n");
	x = printf("%-10s is a string", ""); 
	printf("%d\n", x); 
	x = ft_printf("%-10s is a string", ""); 
	printf("%d\n", x); 

	printf("==TEST_94==\n");
	x = printf("%-010s", "a"); 
	printf("%d\n", x); 
	x = ft_printf("%-010s", "a"); 
	printf("%d\n", x); 

	printf("==TEST_94==\n");
	x = printf("%-10s", ""); 
	printf("%d\n", x); 
	x = ft_printf("%-10s", ""); 
	printf("%d\n", x); 

	printf("==TEST_94==\n");
	x = printf("%10s", ""); 
	printf("%d\n", x); 
	x = ft_printf("%10s", ""); 
	printf("%d\n", x); 

	printf("==TEST_94==\n");
	x = printf("%s", ""); 
	printf("%d\n", x); 
	x = ft_printf("%s", ""); 
	printf("%d\n", x); 

	printf("==TEST_94.1==\n");
	x = printf("%012.2s", ""); 
	printf("%d\n", x); 
	x = ft_printf("%012.2s", ""); 
	printf("%d\n", x); 

	printf("==TEST_95==\n");
	x = printf("%#.O", 0); 
	printf("%d\n", x); 
	x = ft_printf("%#.O", 0); 
	printf("%d\n", x); 

	printf("==TEST_96==\n");
	x = printf("%03.2d", -1); 
	printf("%d\n", x); 
	x = ft_printf("%03.2d", -1); 
	printf("%d\n", x); 

	printf("==TEST_97==\n");
	x = printf("% u", 4294967296); 
	printf("%d\n", x); 
	x = ft_printf("% u", 4294967296); 
	printf("%d\n", x); 

	printf("==TEST_97==\n");
	x = printf("%S", L"Á±≥"); 
	printf("%d\n", x); 
	x = ft_printf("%S", L"Á±≥"); 
	printf("%d\n", x); 

	printf("==TEST_98==\n");
	x = printf("%C", L'猫');
	printf("%d\n", x); 
	x = ft_printf("%C", L'猫');
	printf("%d\n", x); 

	printf("==TEST_98==\n");
	x = printf("%lx, %lx", 4342332, ULONG_MAX);
	printf("%d\n", x); 
	x = ft_printf("%lx, %lx", 4342332, ULONG_MAX);
	printf("%d\n", x); 

	printf("==TEST_99==\n");
	x = printf("%ls", L"暖炉");
	printf("%d\n", x); 
	x = ft_printf("%ls", L"暖炉");
	printf("%d\n", x); 

	printf("==TEST_99==\n");
	x = printf("%03p", 0);
	printf("%d\n", x); 
	x = ft_printf("%03p", 0);
	printf("%d\n", x); 

	printf("==TEST_99==\n");
	x = printf("%#o", 0);
	printf("%d\n", x); 
	x = ft_printf("%#o", 0);
	printf("%d\n", x); 

	printf("==TEST_100==\n");
	x = printf("%+o\n", 42);
//	x = printf("%#+o\n", 4242343);
	x = ft_printf("%+o\n", 42);
//	x = ft_printf("%#+o\n", 4242343);

	printf("==TEST_100==\n");
	x = printf("% 03d", 0);
	printf("%d\n", x); 
	x = ft_printf("% 03d", 0);
	printf("%d\n", x); 

	printf("==TEST_100==\n");
	x = printf("%05.c", 0);
	printf("%d\n", x); 
	x = ft_printf("%05.c", 0);
	printf("%d\n", x); 

	printf("==TEST_100==\n");
	x = printf("%.%\n", 0);
	x = ft_printf("%.3%\n", 0);
	x = printf("%05.6%\n", 0);
	x = ft_printf("%05.6%\n", 0);
//	printf("%d\n", x); 
//	x = ft_printf("%.3%", 0);
//	x = ft_printf("%05.%", 0);
//	printf("%d\n", x); 

	printf("==TEST_100==\n");
	x = printf("%05.Z", 0);
	printf("%d\n", x); 
	x = ft_printf("%05.Z", 0);
	printf("%d\n", x); 

	printf("==TEST_100==\n");
	x = printf("%#.5o", 1012);
	printf("%d\n", x); 
	x = ft_printf("%#.5o", 1012);
	printf("%d\n", x); 

	printf("==TEST_100==\n");
	x = printf("%.5S", L"我是一只猫。");
	printf("%d\n", x); 
	x = ft_printf("%.5S", L"我是一只猫。");
	printf("%d\n", x); 

	printf("==TEST_100==\n");
	x = printf("% 4i", 12221);
	printf("%d\n", x); 
	x = ft_printf("% 4i", 12221);
	printf("%d\n", x); 

//	setlocale(LC_ALL, "");
	printf("==TEST_101==\n");
	x = printf("%s\n", "Lalalala, 100% des gens qui parlent 只 Ly adorent Ly. Ou Presque. 2, 10, 2710,");
	printf("%d\n", x); 
	x = ft_printf("%s\n", "Lalalala, 100% des gens qui parlent 只 Ly adorent Ly. Ou Presque. 2, 10, 2710,");
	printf("%d\n", x); 

	x = printf("%      i\n", 42);
	x = ft_printf("%      i\n", 42);
    x = printf("% i\n", -42);
    x = ft_printf("% i\n", -42);
	x = printf("%- 4i\n", -42);
	x = ft_printf("%- 4i\n", -42);

	printf("==TEST_100==\n");
	x = printf("% 4i%s%C%d%S", 12221, "dsddss", L'只', 324, L"我是一只");
	printf("%d\n", x); 
	x = ft_printf("% 4i%s%C%d%S", 12221, "dsddss", L'只', 324, L"我是一只");
	printf("%d\n", x); 

	printf("==TEST_98==\n");
	x = printf("%C", L'猫');
	printf("%d\n", x); 
	x = ft_printf("%C", L'猫');
	printf("%d\n", x); 

//	setlocale(LC_ALL, "");
	printf("==TEST_98==\n");
	x = printf("%s%C%s", "Lalalala, 100% des gens qui parlent Ly ", L'牐', "adorent Ly. Ou Presque. 2, 10, 2710");
	printf("%d\n", x); 
	x = ft_printf("%s%C%s", "Lalalala, 100% des gens qui parlent Ly ", L'牐', "adorent Ly. Ou Presque. 2, 10, 2710");
	printf("%d\n", x); 

	/*
	 * 
	 *как изменить юникод из структуры на юнион?
	 */

	return (0);
}
