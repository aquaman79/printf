/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 01:53:37 by aquamar           #+#    #+#             */
/*   Updated: 2020/02/07 19:39:48 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dnull2u(void)
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

void	else1u(unsigned int d, int tampon)
{
	if (g_minus != 0)
	{
		precision();
		ft_putnbr_fdu(d, 1);
		min_width();
	}
	else if (g_zero != 0 && tampon < 0)
	{
		g_nmbr2 = g_nmbr1;
		precision();
		ft_putnbr_fdu(d, 1);
	}
	else
	{
		min_width();
		precision();
		ft_putnbr_fdu(d, 1);
	}
}

void	putchar2(unsigned int d, int tampon)
{
	if (g_zero != 0 && g_point == 0)
	{
		g_nmbr2 = g_nmbr1;
		g_nmbr1 = 0;
	}
	if (tampon < 0 && d == 0 && g_point != 0)
	{
		dnull1u();
	}
	else if (g_nmbr2 == 0 && d == 0 && tampon == 0)
	{
		dnull2u();
	}
	else
	{
		else1u(d, tampon);
	}
}

void	traitu(void)
{
	unsigned int	d;
	int				tampon;

	tampon = 0;
	tampon = traitementu(tampon);
	d = va_arg(g_args, unsigned int);
	if (g_nmbr2 == 0 && g_nmbr1 == 0 && g_point == 0)
		ft_putnbr_fdu(d, 1);
	else
	{
		g_nmbr2 -= lenth(d);
		if (g_nmbr2 < 0)
			g_nmbr2 = 0;
		else
			g_nmbr2 = (g_nmbr2 == 0) ? 0 : g_nmbr2;
		g_nmbr1 -= (g_nmbr2 + lenth(d));
		putchar2(d, tampon);
	}
}
