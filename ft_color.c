#include "colors.h"
#include "/home/hamza/my_functions/header.h"

char	*ft_color(char *str, ENUM_REAL_COLORS num)
{
		if (num >=0 && num <= 279)
		{
			oneperson_putstr(START_STRING);
			if (num >= 0 && num < 140)
				oneperson_putstr(COLOR_STRING);
			else
				oneperson_putstr(BACKGROUND_STRING);
			oneperson_putstr(*(*(REAL_COLORS_VARIABLES + (num % 140)) + 1));
			oneperson_putchar('m');
			oneperson_putstr(str);
			oneperson_putstr(EXIT_STRING);
		}
		else
			oneperson_putstr(str);
		return (str);
}
