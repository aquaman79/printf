/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:43:34 by aquamar           #+#    #+#             */
/*   Updated: 2020/01/31 20:43:37 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		passdigits(const char *str, int pr)
{
	while (ft_isdigit(str[pr]) == 1)
		pr++;
	return (pr);
}

void	traitformats(const char *str, int pr)
{
	if (str[pr] == 'd' || str[pr] == 'i')
		traitd();
	if (str[pr] == 'u')
		traitu();
	if (str[pr] == 's')
		traits();
	if (str[pr] == 'c')
		traitc();
	if (str[pr] == 'x' || str[pr] == 'X')
		traitx(str, pr);
	if (str[pr] == 'p')
		traitp();
	if (str[pr] == '%')
		traitpourcentage();
}

int		traitementdesflags(const char *str, int pr)
{
	pr++;
	g_minus = (str[pr] == '-') ? pr++ : 0;
	if (g_minus != 0)
		pr = passminus(str, pr);
	g_zero = (str[pr] == '0') ? pr++ : 0;
	g_nmbr1 = (ft_isdigit(str[pr]) == 1) ? ft_atoi(&str[pr]) : 0;
	pr = (ft_isdigit(str[pr]) == 1) ? passdigits(str, pr) : pr++;
	g_1etoile = (str[pr] == '*') ? pr++ : 0;
	g_point = (str[pr] == '.') ? pr++ : 0;
	g_nmbr2 = (ft_isdigit(str[pr]) == 1) ? ft_atoi(&str[pr]) : 0;
	pr = (ft_isdigit(str[pr]) == 1) ? passdigits(str, pr) : pr++;
	g_2etoile = (str[pr] == '*') ? pr++ : 0;
	traitformats(str, pr);
	pr++;
	return (pr);
}

void	global(void)
{
	g_zero = 0;
	g_pourcentage2 = 0;
	g_minus = 0;
	g_1etoile = 0;
	g_2etoile = 0;
	g_point = 0;
	g_nmbr1 = 0;
	g_nmbr2 = 0;
	g_count = 0;
	g_moin = 0;
}

int		ft_printf(const char *str, ...)
{
	int	bool;
	int	pr;

	global();
	bool = 0;
	pr = 0;
	va_start(g_args, str);
	while (str[pr] != '\0')
	{
		bool = pr;
		while (str[bool] != '%' && str[bool] != '\0')
			bool++;
		while (pr < bool)
			ft_putchar_fd(str[pr++], 1);
		if (str[pr] == '%')
			bool = traitementdesflags(str, pr);
		if (bool == 0)
			return (g_count);
		pr = bool;
		if (str[pr] == '\0')
			return (g_count);
	}
	va_end(g_args);
	return (g_count);
}
