#include "ft_printf.h"
#include "libft.h"

void	ft_out_char(t_data *data)
{
	int	c;

	c = va_arg(data->args, int);
	data->width--;
	if (!data->is_minus && (data->width > 0))
		data->count += ft_out_align(data->width, 0);
	data->count += write(1, &c, 1);
	if (data->is_minus && (data->width > 0))
		data->count += ft_out_align(data->width, 0);
}
