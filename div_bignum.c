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
		quotient += 1;
    }
	quotient -= 1;
	if (is_mod)
		return (remainder);
	return (ft_itoa(quotient));
}
