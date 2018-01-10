/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosa-ta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 22:30:47 by drosa-ta          #+#    #+#             */
/*   Updated: 2017/01/29 23:11:44 by drosa-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char **str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;

	while (**str == '\n' || **str == '\t' || **str == '\r' ||
			**str == '\v' || **str == '\f' || **str == ' ')
		*str += 1;

	if (**str == '-')
		sign = -1;
	if (**str == '-' || **str == '+')
		*str += 1;
	while (**str && **str >= '0' && **str <= '9')
	{
		result = result * 10 + **str - '0';
		*str += 1;	
	}
	return (result * sign);
}
