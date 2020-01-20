#include "ft_printf.h"

void handle_wildcard(t_data *data, t_flag_data *flag_data)
{
	int	j;

	if (flag_data->wildcard1 == TRUE)
	{
		j = va_arg(data->arg, int);
		if (j < 0)
		{
			flag_data->minus = TRUE;
			flag_data->padding = -j;
		}
		else
			flag_data->padding = j;
	}
	if (flag_data->wildcard2 == TRUE)
		flag_data->precision = va_arg(data->arg, int);
}
