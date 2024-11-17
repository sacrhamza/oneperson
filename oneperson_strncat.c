#include "header.h"

char	*oneperson_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int	length;

	length = oneperson_strlen(dest);
	i = 0;
	while (src[i] && i < n)
		 dest[length++] = src[i++];
	dest[length] = '\0';
	return (dest);
}
