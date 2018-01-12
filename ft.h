/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosa-ta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 23:04:27 by drosa-ta          #+#    #+#             */
/*   Updated: 2018/01/09 16:39:04 by drosa-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define BUFF_SIZE 10
int		ft_ptr_atoi(char **str);
char	*add_sub(char **str);
char	*mult_div_mod(char **str);
char	*add_bignum(char *num1, int len1, char *num2, int len2);
char *subtract_bignum(char *num1, int len1, char *num2, int len2);
short	is_valid_expression(char *str, int expr_size, char *base_operands);

#endif
