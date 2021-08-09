#include "ft_printf.h"
#include "libft.h"

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

static int	num_len_radix(unsigned int num, unsigned int radix)
{
	int	len;

	len = 1;
	while (num > (radix - 1))
	{
		len++;
		num /= radix;
	}
	return (len);
}

char	*ft_itoa_base(unsigned int num, unsigned int radix, int is_caps)
{
	char	*str;
	char	*base;
	char	*base_alpha;
	size_t	i;

	str = (char *) malloc(sizeof(char) * (num_len_radix(num, radix) + 1));
	if (!str)
		return (NULL);
	i = 0;
	base = "0123456789abcdef";
	base_alpha = "0123456789ABCDEF";
	if (num == 0)
		str[i++] = '0';
	while (num > 0)
	{
		if (is_caps == 0)
			str[i] = base[num % radix];
		else
			str[i] = base_alpha[num % radix];
		i++;
		num /= radix;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
