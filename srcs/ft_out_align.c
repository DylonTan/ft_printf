#include "ft_printf.h"

int	ft_out_align(int spaces, int is_zero)
{
	int	count;

	count = 0;
	while (spaces > 0)
	{
		if (is_zero == 0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		spaces--;
		count++;
	}
	return (count);
}
