#include "philo.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*res;
	int	i;

	len = ft_strlen(s1);
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

void ft_putnbr(int val)
{
	int	l;
	int v;

	l = 1;
	v = val;
	if (v < 0)
	{
		write(1, "-", 1);
		v = v * -1;
	}
	while ((v = v / 10) > 0)
		l *= 10;
	while (l > 0)
	{
		v = val % l;
		ft_putchar(v + '0');
		val -= v * 10;
		l /= 10;
	}
}