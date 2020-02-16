/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:20:02 by aquamar           #+#    #+#             */
/*   Updated: 2020/02/10 21:20:06 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	else2s(char *d, int r, char *new)
{
	min_width();
	if (d == 0)
	{
		if (g_nmbr2 < 0)
			g_nmbr2 = 6;
		while (g_nmbr2 > 0 && r < 6)
		{
			ft_putchar_fd(new[r], 1);
			g_nmbr2--;
			r++;
		}
	}
	else
	{
		if (g_nmbr2 < 0)
			g_nmbr2 = ft_strlen(d);
		while (g_nmbr2 > 0 && r < ft_strlen(d))
		{
			ft_putchar_fd(d[r], 1);
			g_nmbr2--;
			r++;
		}
	}
	free(new);
}

void	else1s(char *st, int tampon, char *new)
{
	if (st == 0)
	{
		if (g_nmbr2 < 0)
			g_nmbr2 = 6;
		while (g_nmbr2 > 0 && tampon < 6)
		{
			ft_putchar_fd(new[tampon], 1);
			g_nmbr2--;
			tampon++;
		}
	}
	else
	{
		if (g_nmbr2 < 0)
			g_nmbr2 = ft_strlen(st);
		while (g_nmbr2 > 0 && tampon < ft_strlen(st))
		{
			ft_putchar_fd(st[tampon], 1);
			g_nmbr2--;
			tampon++;
		}
	}
	min_width();
	free(new);
}

void	putchars(char *st, int tampon)
{
	char	*new;

	tampon = 0;
	new = (st == 0) ? ft_strdup("(null)") : ft_strdup("\0");
	if (g_nmbr2 < 0 && st == 0 && g_point != 0)
	{
		if (g_minus != 0)
		{
			ft_putstr_fd("(null)", 1);
			min_width();
		}
		if (g_minus == 0)
		{
			min_width();
			ft_putstr_fd("(null)", 1);
		}
	}
	if (g_nmbr2 == 0 && g_point != 0)
		min_width();
	else
		(g_minus != 0) ? else1s(st, tampon, new) : else2s(st, tampon, new);
}

void	traits(void)
{
	char	*st;
	int		r;

	r = 0;
	r = traitemens(r);
	st = va_arg(g_args, char*);
	if (g_nmbr2 == 0 && g_nmbr1 == 0 && g_point == 0)
		(st == 0) ? ft_putstr_fd("(null)", 1) : ft_putstr_fd(st, 1);
	else
	{
		traittemens(st, r);
	}
}
