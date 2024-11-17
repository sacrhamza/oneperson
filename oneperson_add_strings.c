#include <stdarg.h>

//like printf but it returns pointer to char and add all those chars and strings to  just one
//it is perfect but it needs some modification
//today:  04:01 PM 10/08 Tuesday
//after typing that string please free
//enjoy

char	*oneperson_string_realloc(char *type, char *str1,char *str2)
{
	char	*ptr;
	int is_char = 0;
	if (!oneperson_strcmp(type, "%s"))
		ptr = (char *)malloc((oneperson_strlen(str1) + oneperson_strlen(str2) + 1) * sizeof(char));
	else if(!oneperson_strcmp(type, "%c"))
	{
		ptr = (char *)malloc((oneperson_strlen(str1) + 1 + 1) * sizeof(char));
		is_char = 1;
	}
	if (ptr == 0)
		return (0);
	oneperson_strcpy(ptr, str1);
	if (is_char)
		oneperson_strncat(ptr, str2, 1);
	else
		oneperson_strcat(ptr, str2);
	free(str1);
	str1 = 0;
	return (ptr);
}


char 	*oneperson_add_strings(char *str, ...)
{
	va_list	args;
	va_start(args, str);
	int i = 0;
	char *ptr = malloc(1 * sizeof(char));
	*ptr = '\0';
	while (*(str + i))
	{
		if (oneperson_strncmp((str + i), "%s", 2) == 0)
		{
			char *oneperson_string_variable = va_arg(args, char *);
			ptr = oneperson_string_realloc("%s",ptr, oneperson_string_variable);
			i++;
		}
		else if (oneperson_strncmp((str + i), "%c", 2) == 0)
		{
			char oneperson_char_variable = va_arg(args, int);
			ptr = oneperson_string_realloc("%c", ptr, &oneperson_char_variable);
			i++;
		}
		else
			ptr = oneperson_string_realloc("%c", ptr, (str + i));
		i++;
	}
	va_end(args);
	return (ptr);
}

