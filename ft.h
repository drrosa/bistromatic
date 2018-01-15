/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosa-ta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 23:04:27 by drosa-ta          #+#    #+#             */
/*   Updated: 2018/01/14 17:27:15 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define BUFF_SIZE 10
# include "libft.h"
int		ft_ptr_atoi(char **str);
char	*add_sub(char **str);
char	*mult_div_mod(char **str);
char	*add_bignum(char *num1, int len1, char *num2, int len2);
char 	*subtract_bignum(char *num1, int len1, char *num2, int len2);
short	is_valid_expression(char *str, int expr_size, char *base_operands);
t_array	*init_bignum(char *str, int size);
char	*convert_to_neg(char *num, int len);
char	*mult_bignum(char *x, char *y);
int		get_base_value(char c);
int		g_BASE_SIZE;
char	*g_base;
char 	*div_bignum(char *a, char *b);
#endif
