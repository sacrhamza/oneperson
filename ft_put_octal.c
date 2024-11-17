void	ft_put_octal(unsigned int num)
{
	long int number;

	number = num;
	if (number < 0)
	{
		write(1, "-", 1);
		number *= -1;
	}
	if (num >= 8)
	{
		ft_put_octal(num / 8);
		write(1, &"01234567"[num % 8], 1);
	}
	else
		write(1, &"01234567"[num], 1);
}
