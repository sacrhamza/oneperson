#include "header.h"
char	*oneperson_strcat(char *dest, char *src)
{
	int	length;

	length = oneperson_strlen(dest);
	while (*src)
		dest[length++] = *(src++);
	dest[length] = '\0';
	return (dest);
}
