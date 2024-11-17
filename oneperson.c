#include <stdarg.h>
#include "header.h"
#include "exa.c"
#include "ft_put_octal.c"
#include "ft_put_hexadecimal.c"
#include "oneperson_print_color.c"

int	ft_is_color_valid(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| c == '_')
		return (1);
	return (0);
}

int	percent_count(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (!oneperson_strncmp(str, "%s", 2) || !oneperson_strncmp(str, "%d", 2) || !oneperson_strncmp(str, "%c", 2) || !oneperson_strncmp(str, "%o", 2) || !oneperson_strncmp(str, "%x", 2) || !oneperson_strncmp(str, "%%", 2))
			count++;
		str++;
	}
	return (count);
}

void oneperson(char *str, ...)
{
	int	length;
	int	opening_tag;
	int	closing_tag;
	char	*ptr;
	int num = 0;
	opening_tag = 0;
	closing_tag = 0;
	int writed = 1;
	va_list args;
	if (percent_count(str) > 0)
		va_start(args, str);
	while (*str)
	{
		if (!oneperson_strncmp(str, "${", 2))
		{
			length = 0;
			opening_tag = 1;
		}
		if (opening_tag && *str == '}')
			closing_tag = 1;
		if (opening_tag && *str != 0 && !closing_tag && *str != '$' && *str != '{')
		{
			if (length == 0 && ft_is_color_valid(*str))
				ptr = str;
			if (ft_is_color_valid(*str))
				length++;
			else
				opening_tag = 0;
		}
		else if (!opening_tag)
		{
			if (writed == 0)
				oneperson_putchar('m');
			if (*str == '%' && *(str + 1) != '\0')
			{
				if (*(str + 1) == 's')
				{
					char *t = va_arg(args, char *);
					oneperson(t);
				}
				else if (*(str + 1) == 'd' || *(str + 1) == 'i')
				{
					int some_number_here = va_arg(args, int);
					oneperson_putnbr(some_number_here);
				}
				else if (*(str + 1) == 'c')
				{
					char some_char_here = va_arg(args, int);
					oneperson_putchar(some_char_here);
				}
				else if (*(str + 1) == '%')
					oneperson_putchar('%');
				else if (*(str + 1) == 'o')
				{
					unsigned int some_unsinged_octal_here = va_arg(args, unsigned int);
					ft_put_octal(some_unsinged_octal_here);
				}
				else if (*(str + 1) == 'x')
				{
					int some_hexadecimal_here = va_arg(args, int);
					ft_put_hexadecimal(some_hexadecimal_here);
				}
				str += 2;
				writed = 1;
				num = 0;
				continue;
			}
			writed = 1;
			num = 0;
			oneperson_putchar(*str);
		}
		if (opening_tag && closing_tag)
		{
			if (length != 0)
			{
				writed = 0;
				opening_tag = 0;
				closing_tag = 0;
				ptr = oneperson_strndup(ptr, length);
				ft_colored (ptr, num);
				free(ptr);
				num++;
			}
		}

		str++;
	}
	oneperson_putstr(EXIT_STRING);
	va_end(args);
	ptr = 0;
}
