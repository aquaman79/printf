/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:43:48 by aquamar           #+#    #+#             */
/*   Updated: 2020/02/07 18:59:33 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		g_pourcentage2;
int		g_minus;
int		g_1etoile;
int		g_2etoile;
int		g_point;
int		g_nmbr1;
int		g_nmbr2;
int		g_count;
int		g_zero;
va_list	g_args;
int		g_moin;

int		ft_printf(const char *str, ...);
void	global(void);
int		traitementdesflags(const char *str, int pr);
int		passdigits(const char *str, int pr);
int		ft_isdigit(int c);
void	traitformats(const char *str, int pr);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	traitd(void);
void	min_width(void);
void	precision(void);
int		lenth(long nb);
void	traits(void);
void	elseprincipal1(char *st);
void	putchars(char *st, int tampon);
int		traitemens(int tampon);
void	traittemens(char *st, int r);
void	else1s(char *st, int tampon, char *new);
void	else2s(char *st, int tampon, char *new);
int		ft_strlen(const char *s);
int		passminus(const char *fmt, int i);
void	putchar1(int d, int tampon);
int		traitementd(int tampon);
void	principalelse(int d, int tampon);
int		traitementp(int r);
void	elseprincipal1(char *st);
void	ft_putnbr_fdu(unsigned int d, int fd);
int		traitementu(int tampon);
void	dnull1u(void);
void	dnull2u(void);
void	else1u(unsigned int d, int tampon);
void	putchar2(unsigned int d, int tampon);
void	traitu(void);
char	*ft_strdup(const char *str);
void	ft_bzero(void *b, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	traitc(void);
void	putcharc(char ch);
int		traitementx(int r);
int		lenthx(long nb);
void	hexa(unsigned int n, const char *str, int pr);
void	dnull1x(void);
void	dnull2x(void);
void	putchar3(unsigned int d, int r, const char *str, int pr);
void	elseprincipalex(unsigned int d, const char *str, int pr, int r);
void	traitx(const char *str, int pr);
void	hexg_apointer(size_t n);
void	pointer(void *n);
int		lenthp(size_t nb);
int		traitementp(int r);
void	traitp(void);
void	putchar4(void *d, int r);
void	else2p(void *d, int r);
void	else1p(void);
void	dnullp(void);
void	traitpourcentage(void);
void	putchar7(void);
#endif
