/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xutil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:19:03 by aquamar           #+#    #+#             */
/*   Updated: 2020/02/07 16:19:07 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		traitementx(int r)
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

int		lenthx(long nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb = -nb;
		while ((nb = (nb / 16)) != 0)
		{
			i++;
		}
		i = i + 1;
	}
	else
	{
		while ((nb = (nb / 16)) != 0)
		{
			i++;
		}
	}
	return (i);
}

void	hexa(unsigned int n, const char *str, int pr)
{
	if (n / 16)
		hexa(n / 16, str, pr);
	if ((n % 16) >= 10 && str[pr] == 'x')
		ft_putchar_fd((n % 16) + 'a' - 10, 1);
	else if ((n % 16) >= 10 && str[pr] == 'X')
		ft_putchar_fd((n % 16) + 'A' - 10, 1);
	else
		ft_putchar_fd((n % 16) + '0', 1);
}
