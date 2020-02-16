/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:14:41 by aquamar           #+#    #+#             */
/*   Updated: 2020/02/07 23:14:50 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fdu(unsigned int d, int fd)
{
	unsigned int	nouvar;

	nouvar = d;
	if (nouvar <= 9)
	{
		ft_putchar_fd(nouvar + 48, fd);
	}
	if (nouvar > 9)
	{
		ft_putnbr_fd(nouvar / 10, fd);
		ft_putchar_fd(nouvar % 10 + 48, fd);
	}
}

int		traitementu(int tampon)
{
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
	if (g_2etoile != 0)
	{
		g_2etoile = va_arg(g_args, int);
		g_nmbr2 = g_2etoile;
		tampon = g_nmbr2;
	}
	return (tampon);
}

void	dnull1u(void)
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
