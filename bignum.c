#include <stdio.h>
#include "libft.h"

char	*add_bignum(char *num1, int len1, char *num2, int len2);

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

int	second_is_bigger(char *num1, int len1, char *num2, int len2)
{
	if (len1 != len2)
		return (len1 > len2);
	while (--len1 >= 0)
	{
		if (num1[len1] != num2[len1])
			return (num1[len1] > num2[len1]);
	}
	return (0);
}

void	trim_trailing_zeroes(char *num)
{
	int len;
	int is_neg;

	len = ft_strlen(num);
	is_neg = (num[len - 1] == '-') ? 1 : 0;
	while (--len >= 0)
	{
		if (num[len] != '0' && num[len] != '-')
		{
			if (is_neg)
				num[++len] = '-';
			break;
		}
	}
	if (len < 0)
		++len;
	num[++len] = '\0';
}

int	carry_the_one(char *num, int initial_index, int factor)
{
	int index;
   
	index = initial_index;
	while (index > 0)
	{
		if (num[index - 1] != '0')
		{
			num[index - 1] -= 1;
			while (index < initial_index)
				num[index++] = '9';
			return factor + 10;
		}
		index--;
	}
	ft_putendl("you screwed you up big time!! carry_the_one() not working");
	return (0);
}

// TODO: test this shit
char *convert_to_neg(char *num, int len)
{
	//t_array	*char_arr;
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

char *subtract_bignum(char *num1, int len1, char *num2, int len2)
{
	char	*result;
	t_array *char_arr;
	char	*temp;
	int		is_second_bigger;
	int		fac1;
	int		fac2;
	
	if (num1[0] == '-' && num2[0] == '-')
		return subtract_bignum(++num1, --len1, ++num2, --len2);
	else if (num1[0] == '-' && num2[0] != '-') // TODO: protect call to convert_to_neg
		return add_bignum(num1, len1, convert_to_neg(num2, len2), len2 + 1);
	else if (num2[0] == '-' && num1[0] != '-')
		return add_bignum(++num2, --len2, num1, len1);
	if (!(char_arr = init_bignum("", len1)))
		return (0);
	if ((is_second_bigger = second_is_bigger(num2, len2, num1, len1)))
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
		fac1 = len1;
		len1 = len2;
		len2 = fac1;
	}
	len1--;
	len2--;
	while (len1 >= 0 || len2 >= 0)
	{
		fac1 = (len1 < 0) ? 0 : num1[len1] - '0';
		//printf("fac1: %d\n", fac1);
		fac2 = (len2 < 0) ? 0 : num2[len2] - '0';
		//printf("fac2: %d\n", fac2);
		fac1 = (fac1 < fac2) ? carry_the_one(num1, len1, fac1) : fac1; 
		fac1 -= fac2;
		arr_insert(char_arr, fac1 + '0');
		len1--;
		len2--;
	}
	if (is_second_bigger)
		arr_insert(char_arr, '-');
	arr_insert(char_arr, '\0');
	trim_trailing_zeroes(char_arr->str);
	ft_strrev(char_arr->str);
	result = char_arr->str;
	free(char_arr);
	return (result);
}

char *add_bignum(char *num1, int len1, char *num2, int len2)
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
