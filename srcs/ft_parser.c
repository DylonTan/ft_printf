#include "ft_printf.h"
#include "libft.h"

int	ft_is_specifier(char c)
{
	char	*specifiers;
	size_t	i;

	specifiers = "cspdiuxX%";
	i = 0;
	while (specifiers[i])
	{
		if (specifiers[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_parse_specifier(t_data *data, char specifier)
{
	if (specifier == 'c')
		ft_out_char(data);
	else if (specifier == 's')
		ft_out_str(data);
	else if (specifier == 'p')
		ft_out_ptr(data);
	else if (specifier == 'd' || specifier == 'i')
		ft_out_int(data);
	else if (specifier == 'u')
		ft_out_u_int(data);
	else if (specifier == 'x')
		ft_out_hex(data, 0);
	else if (specifier == 'X')
		ft_out_hex(data, 1);
	else if (specifier == '%')
		data->count += write(1, "%", 1);
}

int	ft_parse_flag(t_data *data, const char *str, size_t i)
{
	while (!ft_is_specifier(str[i]))
	{
		if (str[i] == '-')
			data->is_minus = 1;
		else if (str[i] == '.')
			data->is_dot = 1;
		else if (str[i] == '#')
			data->is_hash = 1;
		else if (str[i] == ' ')
			data->is_space = 1;
		else if (str[i] == '+')
			data->is_plus = 1;
		else if (str[i] == '0' && !data->is_minus
			&& !data->precision && !data->width)
			data->is_zero = 1;
		else if (ft_isdigit(str[i]) && data->is_dot)
			data->precision = (data->precision * 10) + (str[i] - '0');
		else if (ft_isdigit(str[i]) && !data->is_dot && !data->precision)
			data->width = (data->width * 10) + (str[i] - '0');
		i++;
	}
	ft_parse_specifier(data, str[i]);
	return (i);
}
