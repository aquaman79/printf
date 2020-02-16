/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:26:34 by aquamar           #+#    #+#             */
/*   Updated: 2019/10/25 22:26:38 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*a;

	a = b;
	i = 0;
	while (len--)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
