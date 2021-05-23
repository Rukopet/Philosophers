#include "philo.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*res;
	int	i;

	len = (int)ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * ++len);
	if (!res)
		return (NULL);
	i = -1;
	while (++i != len)
		res[i] = s1[i];
	return (res);
}

void ft_putchar(char c)
{
	write (1, &c, 1);
}

void ft_putnbr(unsigned long n)
{
	char str[13];
	int length;

	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + (n % 10);
		n = (n / 10);
	}
	if (length > 0)
		length--;
	while (length >= 0)
		write(1, &str[length--], 1);
}