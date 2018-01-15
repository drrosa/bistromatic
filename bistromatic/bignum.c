/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:16:08 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/13 14:57:52 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
