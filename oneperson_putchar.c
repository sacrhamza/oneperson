#include <unistd.h>

void	oneperson_putchar(char c)
{
	write(1, &c, 1);
}
