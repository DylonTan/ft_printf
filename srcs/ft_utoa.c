#include "ft_printf.h"
#include "libft.h"

static int	num_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_strrev(char *str)
{
	size_t	start;
	size_t	end;
	char	temp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (end > start)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	size_t	i;
	int		len;
	char	*str;

	i = 0;
	len = num_len(n);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		i++;
		n /= 10;
	}
	str[len] = '\0';
	return (ft_strrev(str));
}
