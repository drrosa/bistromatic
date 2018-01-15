#include "ft.h"

char *div_bignum(char *a, char *b, int is_mod)
{
   	unsigned long long quotient;
    char *remainder;

    quotient = 0;
	while(a[0] != '-')
    {
		remainder = a;
		a = subtract_bignum( a, ft_strlen(a), b, ft_strlen(b) );
//		a = ft_itoa (ft_atoi(a) - ft_atoi(b));
//      quotient = add_bignum( quotient, ft_strlen(quotient), "1", 1);
		quotient += 1;
    }
//	quotient = subtract_bignum( quotient, ft_strlen(quotient), "1", 1 );
	quotient -= 1;
	if (is_mod)
		return (remainder);
	return (ft_itoa(quotient));
}
/*
#include <stdio.h>
int main(void)
{
    char *a = "40";
    char *b = "3";
    printf("%s\n", div_bignum(a, b));
}
*/
