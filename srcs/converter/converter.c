#include "ft_printf.h"

void converter_s(t_data *data, t_flag_data *flag_data)
{
	(void)flag_data;
	char *str;
	char *str2;
	char *s2;

	handle_wildcard(data, flag_data);
	str = va_arg(data->arg, char *);
	str2 = ft_strdup(str);
	s2 = ft_strnew((flag_data->padding - ft_strlen(str2)));
	if ((ft_strlen(str) > (size_t)(flag_data->precision)) && flag_data->point == TRUE)
		str2[(size_t)(flag_data->precision)] = '\0';
	if (ft_strlen(str2) < (size_t)(flag_data->padding))
		{
			fill(s2, ' ', (flag_data->padding - ft_strlen(str2)));
			if (flag_data->minus == TRUE)
				ft_str_replace_back(&str2, s2);
			else
				ft_str_replace_front(s2, &str2);
		}
	add_str_to_buffer(data, str2);
	free(str2);
	free(s2);
}

void converter_d(t_data *data, t_flag_data *flag_data)
{
	(void)flag_data;
	int i;

	char *str;

	i = va_arg(data->arg, int);
	str = ft_itoa(i);
	add_str_to_buffer(data, str);
}

void converter_c(t_data *data, t_flag_data *flag_data)
{
	char c;

	c = va_arg( data->arg, int );
	converter_other(data, flag_data, c);
}

void converter_i(t_data *data, t_flag_data *flag_data)
{
	(void)flag_data;
	converter_d(data, flag_data);
}

void converter_o(t_data *data, t_flag_data *flag_data)
{
	(void)flag_data;
	unsigned int i;
	char *str;

	i = va_arg(data->arg, unsigned int);
	str = ft_itoa_base(i, 8);
	if (flag_data->sharp == TRUE)
		ft_str_replace_front("0", &str);
	add_str_to_buffer(data, str);
}

void converter_u(t_data *data, t_flag_data *flag_data)
{
	(void)flag_data;
	unsigned int i;
	char *str;

	i = va_arg(data->arg, unsigned int);
	str = ft_itoa_base(i, 10);
	add_str_to_buffer(data, str);
}

void converter_x(t_data *data, t_flag_data *flag_data)
{
	(void)flag_data;
	unsigned int i;
	char *str;

	i = va_arg(data->arg, unsigned int);
	str = ft_itoa_base(i, 16);
	if (flag_data->sharp == TRUE)
		ft_str_replace_front("0x", &str);
	add_str_to_buffer(data, str);
}

void converter_x_maj(t_data *data, t_flag_data *flag_data)
{
	(void)flag_data;
	unsigned int i;
	char *str;

	i = va_arg(data->arg, unsigned int);
	str = ft_itoa_base(i, 16);
	if (flag_data->sharp == TRUE)
		ft_str_replace_front("0X", &str);
	ft_str_toupper(str);
	add_str_to_buffer(data, str);
}

void converter_p(t_data *data, t_flag_data *flag_data)
{
	(void)flag_data;
	unsigned int i;
	char *str;

	i = va_arg(data->arg, unsigned int);
	str = ft_itoa_base(i, 16);
	ft_str_replace_front("0x", &str);
	add_str_to_buffer(data, str);
}

void converter_percent(t_data *data, t_flag_data *flag_data)
{
	(void)flag_data;
	char *str;

	str = ft_strdup("%");
	add_str_to_buffer(data, str);
}

void converter_other(t_data *data, t_flag_data *flag_data, char c)
{
	(void)flag_data;
	char str[2];

	str[0] = c;
	str[1] = '\0';
	add_str_to_buffer(data, str);
}
