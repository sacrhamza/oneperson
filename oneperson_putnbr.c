#include <unistd.h>
#include "oneperson_putchar.c"

void	oneperson_putnbr(long long int number)
{
	if (number < 0)
	{
		write(1, "-", 1);
		number *= -1;
	}
	if (number > 9)
	{
		oneperson_putnbr(number / 10);
		oneperson_putchar((number % 10) + '0');
	}
	else
		oneperson_putchar(number + '0');
}
