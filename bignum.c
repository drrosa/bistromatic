/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:16:08 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/13 12:48:44 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft.h"

void	print_bignum(t_array *num, int size)
{
	while (--size >= 0)
	{
		ft_putchar(num->str[size]);
	}
	ft_putchar('\n');
}

t_array	*init_bignum(char *str, int size)
{
	t_array *num;
	int		i;

	if (!(num = arr_init(size)))
		return (NULL);
	i = 0;
	while (--size >= 0)
	{
		num->str[size] = str[i++];
	}
	return (num);
}

char	*convert_to_neg(char *num, int len)
{
	char	*result;
	int		i;
	int		j;

	if (!(result = ft_memalloc(len + 2)))
		return (0);
	i = 0;
	j = 0;
	result[i++] = '-';
	while (i < len + 1)
	{
		result[i] = num[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

char	*add_bignum(char *num1, int len1, char *num2, int len2)
{
	char	*result;
	t_array *char_arr;
	int		carry;
	int		fac1;
	int		fac2;
	int		factors_neg;

	if (!(char_arr = init_bignum("", len1)))
		return (0);
	/* NEG FACTORS FUNC */
	factors_neg = (num1[0] == '-' && num2[0] == '-') ? 1 : 0;
	if (factors_neg)
	{
		++num1;
		--len1;
		++num2;
		--len2;
	}
	/* NEG FACTORS FUNC */
	if (num1[0] == '-' | num2[0] == '-')
		return (num1[0] == '-') ? subtract_bignum(num2, len2, ++num1, --len1) : subtract_bignum(num1, len1, ++num2, --len2);
	carry = 0;
	len1--;
	len2--;
	while (len1 >= 0 || len2 >= 0 || carry > 0)
	{
		fac1 = (len1 < 0) ? 0 : num1[len1] - '0';
		fac2 = (len2 < 0) ? 0 : num2[len2] - '0';
		fac1 += fac2 + carry;
		arr_insert(char_arr, (fac1 % 10) + '0');
		carry = fac1 / 10;
		len1--;
		len2--;
	}
	if (factors_neg)
		arr_insert(char_arr, '-');
	arr_insert(char_arr, '\0');
	ft_strrev(char_arr->str);
	result = char_arr->str;
	free(char_arr);
	return (result);
}
