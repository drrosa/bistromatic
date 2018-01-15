/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosa-ta <drosa-ta@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:01:22 by drosa-ta          #+#    #+#             */
/*   Updated: 2018/01/14 23:51:36 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

short is_balanced(char *str)
{
	int i;
	int num_open_parens;
	int num_close_parens;

	i = 0;
	num_open_parens = 0;
	num_close_parens = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
			num_open_parens++;
		if (str[i] == ')')
			num_close_parens++;
		i++;
	}
	return (num_open_parens == num_close_parens);
}

short is_correct(char *str, char *base_operands)
{
	int i;
	char *ops;

	i = 0;
	ops = "+-*/%";
	while (str[i] != '\0')
	{
		if (str[i] == '(' && !ft_strchr(ops, str[i-1]))
			return (0);
		else if (str[i] == '(' || str[i] == ')')
			i++; 
		else if (!ft_strchr(base_operands, str[i]) && !ft_strchr(ops, str[i]))
			return (0);
		i++;
	}

	return (1);
}

short is_valid_expression(char *str, unsigned long expr_size, char *base_operands)
{
	short is_valid;

	is_valid = 1;
	if (ft_strlen(str) != expr_size)
		is_valid = 0;
	if (!is_balanced(str))
		is_valid = 0;
	if (!is_correct(str, base_operands))
		is_valid = 0;
	return(is_valid);
}
