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
	i = -1;
	while (num[++i])
		str[i] = num[i];
	while (n--)
		str[i++] = '0';
	str[i] = '\0';
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
	tmp = subtract_bignum(ad_plus_bc, ft_strlen(ad_plus_bc), ac, ft_strlen(ac));
	u_v_w = subtract_bignum(tmp, ft_strlen(tmp), bd, ft_strlen(bd));

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

	if (ft_strlen(x) == 1 && ft_strlen(y) == 1)
		return ( ft_itoa(ft_atoi(x) * ft_atoi(y)) );
	else
	{
		n = split_nums(x, y, &a, &b, &c, &d);
		return (karatsuba(a, b, c, d, n/2));
	}
}

#include<stdio.h>
int main(void)
{
	// printf("%s \n", add_zeros("53", 1));
	printf("%s\n", mult_bignum("123456789", "123456789"));

	return(0);
}