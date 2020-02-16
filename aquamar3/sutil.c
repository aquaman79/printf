/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sutil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:28:31 by aquamar           #+#    #+#             */
/*   Updated: 2020/02/10 20:28:34 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	elseprincipal1(char *st)
{
	if (st == 0)
	{
		g_nmbr1 -= 6;
		g_nmbr2 = 6;
	}
	else
	{
		g_nmbr1 -= ft_strlen(st);
		g_nmbr2 = ft_strlen(st);
	}
}

void	traittemens(char *st, int r)
{
	r = (g_nmbr2 < 0) ? 0 : g_nmbr2;
	if (st != 0)
		r = (g_nmbr2 < ft_strlen(st) && g_nmbr2 >= 0) ? g_nmbr2 : ft_strlen(st);
	else
		r = (g_nmbr2 < 6) ? g_nmbr2 : 6;
	if (st == 0 && g_nmbr2 < 0)
	{
		g_nmbr1 -= 6;
		g_nmbr2 = 6;
	}
	else if (g_nmbr2 != 0)
	{
		if (st == 0)
			g_nmbr1 -= r;
		else
			g_nmbr1 -= r;
	}
	else if (g_nmbr2 == 0 && g_point == 0)
		elseprincipal1(st);
	else
		g_nmbr1 -= g_nmbr2;
	putchars(st, r);
}

int		traitemens(int tampon)
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
