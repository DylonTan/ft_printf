#include "ft_printf.h"
#include "libft.h"

void	ft_out_print_int_sign(t_data *data, char **num)
{
	if ((*num)[0] == '-')
	{
		data->count += write(1, "-", 1);
		(*num)++;
	}
	else if (data->is_space)
		data->count += write(1, " ", 1);
	else if (data->is_plus)
		data->count += write(1, "+", 1);
}

void	ft_out_print_int(t_data *data, char *num)
{
	int	len;

	ft_out_print_int_sign(data, &num);
	len = ft_strlen(num);
	if (data->is_minus)
	{
		if (data->is_zero)
			data->count += ft_out_align(data->precision, 1);
		else
			data->count += ft_out_align(data->precision, 0);
		data->count += write(1, num, len);
		data->count += ft_out_align(data->width, 0);
	}
	else
	{
		if (data->is_zero)
			data->count += ft_out_align(data->width, 1);
		else
			data->count += ft_out_align(data->width, 0);
		data->count += ft_out_align(data->precision, 1);
		data->count += write(1, num, len);
	}
}

void	ft_out_int(t_data *data)
{
	char	*num;
	int		num_len;
	int		abs_len;

	num = ft_itoa(va_arg(data->args, int));
	if (!num)
		return ;
	num_len = (int) ft_strlen(num);
	abs_len = num_len;
	if (num[0] == '-')
		abs_len--;
	if (data->precision > abs_len)
		data->precision = data->precision - abs_len;
	else
		data->precision = 0;
	if (data->width <= 0 || (data->is_minus && (data->width <= abs_len)))
		data->width = 0;
	else
		data->width = data->width - data->precision - num_len;
	ft_out_print_int(data, num);
	free(num);
}

void	ft_out_u_int(t_data *data)
{
	char	*num;
	int		num_len;

	num = ft_utoa(va_arg(data->args, unsigned int));
	num_len = (int) ft_strlen(num);
	if (num[0] == '-')
		num_len--;
	if (data->precision > num_len)
		data->precision = data->precision - num_len;
	else
		data->precision = 0;
	if (data->width > (data->precision + num_len))
		data->width = data->width - data->precision - num_len;
	else
		data->width = 0;
	ft_out_print_int(data, num);
	free(num);
}
