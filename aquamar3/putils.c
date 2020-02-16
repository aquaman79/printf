/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:13:14 by aquamar           #+#    #+#             */
/*   Updated: 2020/02/07 16:13:19 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexg_apointer(size_t n)
{
	if (n / 16)
		hexg_apointer(n / 16);
	if ((n % 16) >= 10)
		ft_putchar_fd((n % 16) + 'a' - 10, 1);
	else
		ft_putchar_fd((n % 16) + '0', 1);
}

void	pointer(void *n)
{
	ft_putstr_fd("0x", 1);
	hexg_apointer((size_t)n);
}

int		lenthp(size_t nb)
{
	int	i;

	i = 1;
	while ((nb = (nb / 16)) != 0)
	{
		i++;
	}
	return (i + 2);
}

int		traitementp(int r)
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
		r = g_nmbr2;
	}
	return (r);
}
