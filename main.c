/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosa-ta <drosa-ta@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:26:44 by drosa-ta          #+#    #+#             */
/*   Updated: 2018/01/14 19:27:17 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
//TODO: remove stdio
#include <stdio.h>
#include "libft.h"

char	*g_base;
int		g_BASE_SIZE;

char	*do_op(char *num_a, char *num_b, char op)
{
	//printf("a = %s, b = %s op = %c\n", num_a, num_b, op);
	//int result;
	//int a = ft_ptr_atoi(&num_a);
	//int b = ft_ptr_atoi(&num_b);
	//num_a = ft_itoa(a);
	//num_b = ft_itoa(b);
	
	//result = 0;
	if (op == '+')
		return (add_bignum(num_a, ft_strlen(num_a), num_b, ft_strlen(num_b)));
		// result = a + b;
	else if (op == '-')
		return (subtract_bignum(num_a, ft_strlen(num_a), num_b, ft_strlen(num_b)));
	else if (op == '*')
		return (mult_bignum(num_a, num_b));
	else if (op == '/')
		return (div_bignum(num_a, num_b));
	/*else if (op == '%' && b != 0)
		result = (a % b);
	return (ft_itoa(result));*/
	return (0);
}

char	*parse_base_num(char **p_str) //account for multiple positive negatives, etc.
{
	char	*num;
	int		i;
	int		n_count;
	int		k;
	char	*ops;

	ops = "(+-*/%)";
	i = 0;
	n_count = 0;
	while (**p_str == '-' || **p_str == '+')
	{
		n_count = (**p_str == '-') ? n_count + 1 : n_count;
		(*p_str)++;
	}
	n_count = (n_count % 2 == 1) ? 1 : 0;
	i = 0;
	while ((*p_str)[i] && !ft_strchr(ops, (*p_str)[i]))
		i++;
	if (!(num = (char*)ft_memalloc(n_count + i + 1)))
		return (0);
	i = 0;
	k = 0;
	if (n_count)
		num[k++] = '-';
	while ((*p_str)[i] && !ft_strchr(ops, (*p_str)[i]))
		num[k++] = (*p_str)[i++];
	num[k] = '\0';
	*p_str = &(*p_str)[i];
	printf("num: %s\n", num);
	return (num);
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
	return (parse_base_num(str));
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
		if (!a)
			a = "0";
		// printf("a = %s, b = %s\n", a, b);
		a = do_op(a, b, op);
	}

	return (a);
}

int	set_buffer(t_array *buff)
{
	char	in_buff[BUFF_SIZE + 1];
	int		reader;
	int		i;

	buff->size = 20;
	buff->used = 0;
	if (!(buff->str = ft_memalloc(buff->size * sizeof(char))))
		return (0);
	while ((reader = read(0, in_buff, BUFF_SIZE)))
	{
		if (reader == -1)
			return (0);
		in_buff[reader] = '\0';
		i = 0;
		while (in_buff[i])
			arr_insert(buff, in_buff[i++]);
	}
	return (1);
}

char	*eval_expr(char *str)
{
	return (add_sub(&str));
}

// void	test()
// {
// 	printf("%s\n", eval_expr("3+6"));
// 	printf("%s\n", eval_expr("--++-6(12)"));
// 	printf("%s\n", eval_expr("--++-6*12"));
// 	printf("%s\n", eval_expr("-(12-(4*32))"));
// 	printf("%s\n", eval_expr("-(12-(4*32)"));
// 	printf("%s\n", eval_expr("-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))"));
// }

// int		main(void)
// {
// 	test();
// 	return (0);
// }

int	get_base_value(char c)
{
	int i;
	i = 0;
	//printf("get_b_val of %c\n", c);
	while (g_base[i])
	{
		if (c ==  g_base[i])
			return (i);
		i++;
	}
	ft_putendl("Wtf?! Not a valid base symbol");
	return (-1);
}

int	main(int argc, char **argv)
{
	char	*result;
	int		input_size;
	//int		base_size;
	t_array	buff;

 	// printf("IS_VALID: %hd\n", is_valid_expression("6*12", 4, "0123456789"));
 	// printf("%s\n", add_sub(&(result)));
 	//printf("IS_VALID: %hd\n", is_valid_expression("6*12", 4, "0123456789"));
	if (argc != 3)
		return (1);
	g_BASE_SIZE = ft_strlen(argv[1]);
	g_base = argv[1];
	// TODO: validate input
	input_size = ft_atoi(argv[2]);
	
	if (!set_buffer(&buff))
	{
		return (1);
	}
	buff.str[input_size] = '\0';
	// printf("%s, %d, %s\n", buff.str, input_size, argv[1]);	
	// printf("\nVALID?: %hd\n", is_valid_expression(buff.str, input_size, argv[1]));
	if (is_valid_expression(buff.str, input_size, argv[1]))
		result = add_sub(&(buff.str));
	else
		ft_putstr("syntax error");
	// TODO: display in correct base
	ft_putendl(result);
	return (0);
}

// TODO
// Error check parens, size, valid op before '(', valid chars
