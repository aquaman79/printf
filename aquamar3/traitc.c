/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:43:34 by aquamar           #+#    #+#             */
/*   Updated: 2020/02/07 19:04:00 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putcharc(char ch)
{
	if (g_1etoile != 0 && g_point == 0)
	{
		g_nmbr1 = 1 * g_nmbr1;
		g_nmbr2 = 0;
	}
	if (g_minus != 0)
		ft_putchar_fd(ch, 1);
	min_width();
	if (g_minus == 0)
		ft_putchar_fd(ch, 1);
}

void	traitc(void)
{
	char	ch;
	int		tampon;

	tampon = 0;
	if (g_1etoile != 0)
	{
		g_1etoile = va_arg(g_args, int);
		g_nmbr1 = g_1etoile;
		if (g_nmbr1 < 0)
		{
			g_minus = 1;
			g_nmbr1 = -g_nmbr1;
		}
	}
	ch = va_arg(g_args, int);
	if (g_nmbr1 == 0 && g_point == 0)
		ft_putchar_fd(ch, 1);
	else
	{
		g_nmbr1 -= 1;
		putcharc(ch);
	}
}
