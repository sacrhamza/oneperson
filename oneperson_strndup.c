#include <stdlib.h>
char	*oneperson_strndup(char *str, unsigned int n)
{
	char	*ptr;
	ptr = (char *)malloc((n + 1) * sizeof(str));
	if (ptr == 0)
		return (0);
	oneperson_strncpy(ptr, str, n);
	return (ptr);
}
