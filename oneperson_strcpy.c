char	*oneperson_strcpy(char *dest,const char *src)
{
	unsigned int	i;

	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
