#include <unistd.h>

void	oneperson_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
