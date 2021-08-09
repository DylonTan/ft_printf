#include "ft_printf.h"

static void	init_data(t_data *data)
{
	data->is_minus = 0;
	data->is_zero = 0;
	data->is_dot = 0;
	data->is_hash = 0;
	data->is_space = 0;
	data->is_plus = 0;
	data->width = 0;
	data->precision = 0;
	data->count = 0;
}

int	ft_printf(const char *str, ...)
{
	t_data	*data;
	size_t	i;
	int		count;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		return (-1);
	va_start(data->args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		init_data(data);
		if (str[i] == '%')
			i = ft_parse_flag(data, str, i + 1);
		else
			count += write(1, &str[i], 1);
		count += data->count;
		i++;
	}
	va_end(data->args);
	free(data);
	return (count);
}
