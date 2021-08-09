#include "ft_printf.h"
#include "libft.h"

void	ft_out_str(t_data *data)
{
	const char	*str;
	int			len;

	str = va_arg(data->args, char *);
	if (!str)
		str = "(null)";
	len = (int) ft_strlen(str);
	if (!data->precision && data->is_dot)
		data->precision = 0;
	else if (!data->precision || data->precision > len)
		data->precision = len;
	if (data->width > data->precision)
		data->width = data->width - data->precision;
	else
		data->width = 0;
	if (data->is_minus)
	{
		data->count += write(1, str, data->precision);
		data->count += ft_out_align(data->width, 0);
	}
	else
	{
		data->count += ft_out_align(data->width, 0);
		data->count += write(1, str, data->precision);
	}
}
