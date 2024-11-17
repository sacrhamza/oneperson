void	ft_put_hexadecimal(int num)
{
	long int number;

	number = num;
	if (number < 0)
	{
		write(1, "-", 1);
		number *= -1;
	}
	if (num >= 16)
	{
		ft_put_hexadecimal(num / 16);
		write(1, &"0123456789abcdef"[num % 16], 1);
	}
	else
		write(1, &"0123456789abcdef"[num], 1);
}
