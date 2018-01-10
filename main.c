/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosa-ta <drosa-ta@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:26:44 by drosa-ta          #+#    #+#             */
/*   Updated: 2018/01/08 14:27:00 by drosa-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include <stdio.h>

char *add_sub(char **str);
char *mult_div_mod(char **str);

char	*do_op(char *num_a, char *num_b, char op)
{
	int result;
	int a = ft_atoi(&num_a);
	int b = ft_atoi(&num_b);

	result = 0;
	if (op == '+')
		result = (a + b);
	else if (op == '-')
		result = (a - b);
	else if (op == '*')
		result = (a * b);
	else if (op == '/' && b != 0)
		result = (a / b);
	else if (op == '%' && b != 0)
		result = (a % b);
	return (ft_itoa(result));
}

char	*parse_num(char **str)
{
	char *a;

	while (**str == ' ')
		*str += 1;
	if (**str == '(')
	{
		*str += 1;
		a = add_sub(str);
		if (**str == ')')
			*str += 1;
		return (a);
	}
	return (ft_itoa(ft_atoi(str)));
}

char	*mult_div_mod(char **str)
{
	char	*a;
	char	*b;
	char	op;

	a = parse_num(str);
	while (**str)
	{
		while (**str == ' ')
			*str += 1;
				
		op = **str;

		if (op != '*' && op != '/' && op != '%')
			return (a);
		*str += 1;
		b = parse_num(str);
		a = do_op(a, b, op);
	}
	return (a);
}

char	*add_sub(char **str)
{
	char	*a;
	char	*b;
	char	op;

	if (**str == '-')
		a = 0;
	else
		a = mult_div_mod(str);
	while (**str)
	{
		while (**str == ' ')
			*str += 1;

		op = **str;
		if (op != '+' && op != '-')
			return (a);
		*str += 1;
		b = mult_div_mod(str);
		if(!a)
			a = "0";
		a = do_op(a, b, op);
	}
	
	return (a);
}

char	*eval_expr(char *str)
{
	return (add_sub(&str));
}


void test()
{
	printf("%s\n", eval_expr("3+6"));
	printf("%s\n", eval_expr("--++-6(12)"));
	printf("%s\n", eval_expr("--++-6*12"));
	printf("%s\n", eval_expr("-(12-(4*32))"));
	printf("%s\n", eval_expr("-(12-(4*32)"));
	printf("%s\n", eval_expr("-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))"));
}

int	main()
{
	test();
	return (0);
}

// int	main(int ac, char **av)
// {
// 	if (ac > 1)
// 	{
// 		printf("%s\n", eval_expr(av[1]));
// 		ft_putchar('\n');
// 	}
// 	return (0);
// }