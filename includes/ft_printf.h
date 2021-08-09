#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_data {
	va_list	args;
	int		is_minus;
	int		is_zero;
	int		is_dot;
	int		is_hash;
	int		is_space;
	int		is_plus;
	int		width;
	int		precision;
	int		count;
}	t_data;

void	ft_parse_specifier(t_data *data, char specifier);

int		ft_parse_flag(t_data *data, const char *str, size_t i);

void	ft_out_char(t_data *data);

void	ft_out_str(t_data *data);

void	ft_out_int(t_data *data);

void	ft_out_u_int(t_data *data);

int		ft_out_align(int spaces, int is_zero);

void	ft_out_hex(t_data *data, int is_caps);

void	ft_out_ptr(t_data *data);

char	*ft_utoa(unsigned int n);

char	*ft_itoa_base(unsigned long long num,
			unsigned long long radix, int is_caps);

int		ft_printf(const char *str, ...);

#endif
