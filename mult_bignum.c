/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_bignum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosa-ta <drosa-ta@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:14:58 by drosa-ta          #+#    #+#             */
/*   Updated: 2018/01/13 15:40:03 by drosa-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft.h"
#include<stdio.h>
char	*mult_bignum(char *x, char *y);

int split_nums(char *x, char *y, char **a, char **b, char **c, char **d)
{
	int x_len;
	int y_len;
	int max;
	int m2;

	x_len = ft_strlen(x);
	y_len = ft_strlen(y);
	max = x_len < y_len ? y_len : x_len;
	m2 = max/2;

	*a = x_len - m2 >= 1 ? ft_strncpy(ft_strnew(x_len - m2), x, x_len - m2) : "0";
	*b = x_len >= m2 ? ft_strcpy(ft_strnew(m2), &x[x_len - m2]) : ft_strdup(x);
	*c = y_len - m2 >= 1 ? ft_strncpy(ft_strnew(y_len - m2), y, y_len - m2) : "0";
	*d = y_len >= m2 ? ft_strcpy(ft_strnew(m2), &y[y_len - m2]) : ft_strdup(y);

	return (max);
}

char *add_zeros(char *num, int n)
{
	char *str;
	int i;
	str = (char *)malloc(sizeof(char) * (ft_strlen(num) + n + 1));
	i = 0;
	while (num[i])
	{
		str[i] = num[i];
		i++;
	}
	
	while (n--)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}


#include <stdlib.h>

char	*ft_strnewer(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (str)
	{
		*(str + size) = 0;
		while (size--)
			*(str + size) = 0;
	}
	return (str);
}


char *karatsuba(char *a, char *b, char *c, char *d, int m)
{
	char *ac;
	char *bd;
	char *ad_plus_bc;
	char *tmp;
	char *u_v_w;

	ac = mult_bignum(a, c);
	bd = mult_bignum(b, d);
	ad_plus_bc = mult_bignum(add_bignum(a, ft_strlen(a),b, ft_strlen(b)),
							 add_bignum(c, ft_strlen(c), d, ft_strlen(d)));
	// printf("a: %s, b: %s, c: %s, d: %s\n", a, b, c, d);
	// ad_plus_bc = mult_bignum( ft_itoa( ft_atoi(a) + ft_atoi(b) ), ft_itoa( ft_atoi(c) + ft_atoi(d) ) );
	// printf("ad+bc: %s\n", ad_plus_bc);
	tmp = subtract_bignum(ad_plus_bc, ft_strlen(ad_plus_bc), ac, ft_strlen(ac));
	// tmp = ft_itoa( ft_atoi(ad_plus_bc) - ft_atoi(ac) );
	u_v_w = subtract_bignum(tmp, ft_strlen(tmp), bd, ft_strlen(bd));
	// u_v_w = ft_itoa( ft_atoi(tmp) - ft_atoi(bd) );

	// printf("ac: %s, bd: %s, ad+bc: %s, u-v-w: %s\n", ac, bd, ad_plus_bc, u_v_w);
	// printf("m*2: %d, m: %d\n", m*2, m);
	// add_zeros(ac, m*2); add_zeros(u_v_w, m);

	ac = ac[0] == '0' ? "0" : add_zeros(ac, m*2);
	u_v_w = u_v_w[0] == '0' ? "0" : add_zeros(u_v_w, m);
	tmp = add_bignum(ac, ft_strlen(ac),u_v_w, ft_strlen(u_v_w));
	tmp = add_bignum(tmp, ft_strlen(tmp), bd, ft_strlen(bd)); 
	return (tmp);
}

char	*mult_bignum(char *x, char *y)
{
	int n;
	char *a;
	char *b;
	char *c;
	char *d;

	// printf("x: %s, y: %s\n", x, y);
	if (ft_strlen(x) == 1 && ft_strlen(y) == 1)
		return ( ft_itoa(ft_atoi(x) * ft_atoi(y)) );
	else
	{
		n = split_nums(x, y, &a, &b, &c, &d);
	// printf("a: %s, b: %s, c: %s, d: %s\n", a, b, c, d);
		return (karatsuba(a, b, c, d, n/2));
	}
}


int main(void)
{
	// printf("%s \n", add_zeros("53", 1));
	printf("%s\n", mult_bignum("123456789", "123456789"));

	return(0);
}