#include <stdlib.h>
char	*oneperson_strdup(char *str)
{
	char	*ptr;
	ptr = (char *)malloc((oneperson_strlen(str) + 1) * sizeof(str));
	if (ptr == 0)
		return (0);
	oneperson_strcpy(ptr, str);
	return (ptr);
}
