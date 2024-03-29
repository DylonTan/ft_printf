#include <limits.h>
#include "ft_printf.h"
#include "libft.h"

static void	ft_out_print_hex_prefix(t_data *data, int is_caps)
{
	if (data->is_hash)
	{
		if (is_caps)
			data->count += write(1, "0X", 2);
		else
			data->count += write(1, "0x", 2);
	}
}

static void	ft_out_print_hex(t_data *data, char *num, int is_caps)
{
	if (!(ft_strlen(num) == 1 && num[0] == '0'))
		ft_out_print_hex_prefix(data, is_caps);
	if (data->is_minus)
	{
		if (data->is_zero)
			data->count += ft_out_align(data->precision, 1);
		else
			data->count += ft_out_align(data->precision, 0);
		ft_putstr_fd(num, 1);
		data->count += ft_out_align(data->width, 0);
	}
	else
	{
		if (data->is_zero)
			data->count += ft_out_align(data->width, 1);
		else
			data->count += ft_out_align(data->width, 0);
		data->count += ft_out_align(data->precision, 1);
		ft_putstr_fd(num, 1);
	}
	data->count += ft_strlen(num);
}

void	ft_out_hex(t_data *data, int is_caps)
{
	long long		n;
	char			*num;
	int				num_len;

	n = va_arg(data->args, int);
	if (n < 0)
		n = UINT_MAX + n + 1;
	if (n == 0)
		num = ft_strdup("0");
	else
		num = ft_itoa_base(n, 16, is_caps);
	if (!num)
		return ;
	num_len = (int) ft_strlen(num);
	if (data->precision > num_len)
		data->precision = data->precision - num_len;
	else
		data->precision = 0;
	if (data->width > (data->precision + num_len + (data->is_hash * 2)))
		data->width = data->width - data->precision
			- num_len - + (data->is_hash * 2);
	else
		data->width = 0;
	ft_out_print_hex(data, num, is_caps);
	free(num);
}

static void	ft_handle_nptr(t_data *data, long long n, char **num)
{
	*num = ft_itoa_base(n, 16, 0);
	data->is_hash = 1;
}

void	ft_out_ptr(t_data *data)
{
	long long		n;
	char			*num;
	int				num_len;

	n = (long long) va_arg(data->args, void *);
	if (n < 0)
		n = ULLONG_MAX + n + 1;
	if (n == 0)
		num = ft_strdup("0x0");
	else
		ft_handle_nptr(data, n, &num);
	if (!num)
		return ;
	num_len = (int) ft_strlen(num);
	if (data->precision > num_len)
		data->precision = data->precision - num_len;
	else
		data->precision = 0;
	if (data->width > (data->precision + num_len + (data->is_hash * 2)))
		data->width = data->width - data->precision
			- num_len - + (data->is_hash * 2);
	else
		data->width = 0;
	ft_out_print_hex(data, num, 0);
	free(num);
}
