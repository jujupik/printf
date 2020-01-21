#include "ft_printf.h"

void converter_s(t_data *data, t_flag_data *flag_data)
{
	char *str;
	char *str2;

	handle_wildcard(data, flag_data);
	str = va_arg(data->arg, char *);
	str2 = ft_strdup(str);
	if ((ft_strlen(str) > (size_t)(flag_data->precision)) && flag_data->point == TRUE)
		str2[(size_t)(flag_data->precision)] = '\0';
	handle_padding(flag_data, &str2);
	add_str_to_buffer(data, str2);
	free(str2);
}

void converter_d(t_data *data, t_flag_data *flag_data)
{
	long long i;
	BOOL neg;
	char *str;

	neg = FALSE;
	handle_wildcard(data, flag_data);
	i = handle_lh(data, flag_data);
	if (i < 0)
	{
		neg = TRUE;
		i = -i;
	}
	str = ft_itoa(i);
	handle_precision(flag_data, &str);
	if (flag_data->space == TRUE && flag_data->plus == FALSE && neg == FALSE)
		ft_str_replace_front(" ", &str);
	if (flag_data->plus == TRUE)
	{
		if (i >= 0)
			ft_str_replace_front("+", &str);
	}
	if (neg == TRUE)
		ft_str_replace_front("-", &str);
	handle_padding_num(flag_data, &str);
	add_str_to_buffer(data, str);
	free(str);
}

void converter_c(t_data *data, t_flag_data *flag_data)
{
	char c;
	char *str;

	handle_wildcard(data, flag_data);
	c = va_arg( data->arg, int );
	str = ft_strnew_c(1, c);
	handle_padding(flag_data, &str);
	add_str_to_buffer(data, str);
	free(str);
}

void converter_i(t_data *data, t_flag_data *flag_data)
{
	converter_d(data, flag_data);
}

void converter_o(t_data *data, t_flag_data *flag_data)
{
	unsigned long long i;
	char *str;

	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	str = ft_itoa_base(i, 8);
	if (flag_data->sharp == TRUE && str[0] != '0')
		ft_str_replace_front("0", &str);
	handle_precision(flag_data, &str);
	handle_padding_num(flag_data, &str);
	add_str_to_buffer(data, str);
	free(str);
}

void converter_u(t_data *data, t_flag_data *flag_data)
{
	unsigned int i;
	char *str;

	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	str = ft_itoa_base(i, 10);
	handle_precision(flag_data, &str);
	handle_padding_num(flag_data, &str);
	add_str_to_buffer(data, str);
	free(str);
}

void converter_x(t_data *data, t_flag_data *flag_data)
{
	unsigned int i;
	char *str;

	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	str = ft_itoa_base(i, 16);
	if (flag_data->sharp == TRUE)
		ft_str_replace_front("0x", &str);
	handle_precision(flag_data, &str);
	handle_padding_num(flag_data, &str);
	add_str_to_buffer(data, str);
	free(str);
}

void converter_x_maj(t_data *data, t_flag_data *flag_data)
{
	unsigned int i;
	char *str;

	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	str = ft_itoa_base(i, 16);
	if (flag_data->sharp == TRUE)
		ft_str_replace_front("0X", &str);
	handle_precision(flag_data, &str);
	handle_padding_num(flag_data, &str);
	ft_str_toupper(str);
	add_str_to_buffer(data, str);
	free(str);
}

void converter_p(t_data *data, t_flag_data *flag_data)
{
	unsigned int i;
	char *str;

	handle_wildcard(data, flag_data);
	i = va_arg(data->arg, unsigned int);
	str = ft_itoa_base(i, 16);
	ft_str_replace_front("0x", &str);
	handle_padding_num(flag_data, &str);
	add_str_to_buffer(data, str);
	free(str);
}

void converter_percent(t_data *data, t_flag_data *flag_data)
{
	(void)flag_data;
	char *str;

	str = ft_strdup("%");
	add_str_to_buffer(data, str);
	free(str);
}

void converter_other(t_data *data, t_flag_data *flag_data, char c)
{
	(void)flag_data;
	char str[2];

	str[0] = c;
	str[1] = '\0';
	add_str_to_buffer(data, str);
}
