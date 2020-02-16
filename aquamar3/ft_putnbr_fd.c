/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:44:34 by aquamar           #+#    #+#             */
/*   Updated: 2020/01/31 20:44:36 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nouvar;

	nouvar = (n < 0) ? -n : n;
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
