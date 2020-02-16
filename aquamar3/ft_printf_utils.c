/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:44:01 by aquamar           #+#    #+#             */
/*   Updated: 2020/01/31 20:44:07 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	min_width(void)
{
	while (g_nmbr1 > 0)
	{
		ft_putchar_fd(' ', 1);
		g_nmbr1--;
	}
}

void	precision(void)
{
	while (g_nmbr2 > 0)
	{
		ft_putchar_fd('0', 1);
		g_nmbr2--;
	}
}

int		passminus(const char *str, int pr)
{
	if (str[pr] == '-')
	{
		while (str[pr] == '-')
			pr++;
	}
	return (pr);
}
