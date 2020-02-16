/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:29:22 by aquamar           #+#    #+#             */
/*   Updated: 2019/10/25 22:29:27 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	ft_bzero(new, len);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
