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

void	converter_d(t_data *data, t_flag_data *flag_data)
{
	long long	i;
	BOOL		neg;
	char		*str;

	neg = FALSE;
	handle_wildcard(data, flag_data);
	i = handle_lh(data, flag_data);
	if (i < 0)
	{
		flag_data->plus = FALSE;
		neg = TRUE;
		i = -i;
	}
	if (i == 0 && flag_data->point == TRUE && flag_data->precision == 0)
		str = ft_strnew(1);
	else
		str = ft_itoa(i);
	handle_precision(flag_data, &str);
	if (flag_data->zero == TRUE)
	{
		if (flag_data->plus == TRUE || flag_data->space == TRUE || neg == TRUE)
			flag_data->padding--;
		handle_padding_num(flag_data, &str);
	}
	if (flag_data->space == TRUE && flag_data->plus == FALSE && neg == FALSE)
		ft_str_replace_front(" ", &str);
	if (neg == TRUE)
		ft_str_replace_front("-", &str);
	if (flag_data->plus == TRUE)
		ft_str_replace_front("+", &str);
	if (flag_data->zero == FALSE)
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
	handle_padding_c(flag_data, &str);
	add_str_to_buffer(data, str);
	if (c == '\0')
		add_char_to_buffer(data, '\0');
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
	if (i == 0 && flag_data->point == TRUE && flag_data->precision == 0)
		str = ft_strnew(1);
	else
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
	if (i == 0 && flag_data->point == TRUE && flag_data->precision == 0)
		str = ft_strnew(1);
	else
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

	flag_data->plus = FALSE;
	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	if (i == 0 && flag_data->point == TRUE && flag_data->precision == 0)
		str = ft_strnew(1);
	else
		str = ft_itoa_base(i, 16);
	handle_precision(flag_data, &str);
	if (flag_data->sharp == TRUE && flag_data->zero == FALSE && i != 0)
		ft_str_replace_front("0x", &str);
	else if (flag_data->sharp == TRUE && flag_data->zero == TRUE && i != 0)
		flag_data->padding = flag_data->padding - 2;
	handle_padding_num(flag_data, &str);
	if (flag_data->sharp == TRUE && flag_data->zero == TRUE && i != 0)
		ft_str_replace_front("0x", &str);
	add_str_to_buffer(data, str);
	free(str);
}

void converter_x_maj(t_data *data, t_flag_data *flag_data)
{
	unsigned int i;
	char *str;

	flag_data->plus = FALSE;
	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	if (i == 0 && flag_data->point == TRUE && flag_data->precision == 0)
		str = ft_strnew(1);
	else
		str = ft_itoa_base(i, 16);
	handle_precision(flag_data, &str);
	if (flag_data->sharp == TRUE && flag_data->zero == FALSE && i != 0)
		ft_str_replace_front("0X", &str);
	else if (flag_data->sharp == TRUE && flag_data->zero == TRUE && i != 0)
		flag_data->padding = flag_data->padding - 2;
	handle_padding_num(flag_data, &str);
	if (flag_data->sharp == TRUE && flag_data->zero == TRUE && i != 0)
		ft_str_replace_front("0X", &str);
	ft_str_toupper(str);
	add_str_to_buffer(data, str);
	free(str);
}

void converter_p(t_data *data, t_flag_data *flag_data)
{
	unsigned int i;
	char *str;

	flag_data->plus = FALSE;
	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	if (i == 0 && flag_data->point == TRUE && flag_data->precision == 0)
		str = ft_strnew(1);
	else
		str = ft_itoa_base(i, 16);
	handle_precision(flag_data, &str);
	if (flag_data->zero == FALSE)
		ft_str_replace_front("0x", &str);
	else if (flag_data->zero == TRUE)
		flag_data->padding = flag_data->padding - 2;
	handle_padding_num(flag_data, &str);
	if (flag_data->zero == TRUE)
		ft_str_replace_front("0x", &str);
	add_str_to_buffer(data, str);
	free(str);
}

void converter_percent(t_data *data, t_flag_data *flag_data)
{
	(void)flag_data;
	char *str;

	handle_wildcard(data, flag_data);
	str = ft_strdup("%");
	handle_padding(flag_data, &str);
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
