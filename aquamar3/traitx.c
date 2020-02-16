/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:18:45 by aquamar           #+#    #+#             */
/*   Updated: 2020/02/07 16:18:55 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dnull1x(void)
{
	if (g_minus != 0)
	{
		ft_putchar_fd('0', 1);
		min_width();
	}
	if (g_minus == 0)
	{
		if (g_zero != 0)
		{
			g_nmbr2 = g_nmbr1;
			precision();
		}
		else
		{
			min_width();
		}
		ft_putchar_fd('0', 1);
	}
}

void	dnull2x(void)
{
	if (g_point == 0)
	{
		if (g_minus == 0)
			min_width();
		ft_putchar_fd('0', 1);
		if (g_minus != 0)
			min_width();
	}
	else
	{
		g_nmbr1 = g_nmbr1 + 1;
		min_width();
	}
}

void	elseprincipalex(unsigned int d, const char *str, int pr, int r)
{
	if (g_minus != 0)
	{
		precision();
		hexa(d, str, pr);
		min_width();
	}
	else if (g_zero != 0 && r < 0)
	{
		g_nmbr2 = g_nmbr1;
		precision();
		hexa(d, str, pr);
	}
	else
	{
		min_width();
		precision();
		hexa(d, str, pr);
	}
}

void	putchar3(unsigned int d, int r, const char *str, int pr)
{
	if (g_zero != 0 && g_point == 0)
	{
		g_nmbr2 = g_nmbr1;
		g_nmbr1 = 0;
	}
	if (r < 0 && d == 0 && g_point != 0)
	{
		dnull1x();
	}
	else if (g_nmbr2 == 0 && d == 0 && r == 0)
	{
		dnull2x();
	}
	else
	{
		elseprincipalex(d, str, pr, r);
	}
}

void	traitx(const char *str, int pr)
{
	unsigned int	d;
	int				r;

	r = 0;
	r = traitementx(r);
	d = va_arg(g_args, unsigned int);
	if (g_nmbr2 == 0 && g_nmbr1 == 0 && g_point == 0)
		hexa(d, str, pr);
	else
	{
		g_nmbr2 -= lenthx(d);
		if (g_nmbr2 < 0)
			g_nmbr2 = 0;
		else
			g_nmbr2 = (g_nmbr2 == 0) ? 0 : g_nmbr2;
		g_nmbr1 -= (g_nmbr2 + lenthx(d));
		putchar3(d, r, str, pr);
	}
}
