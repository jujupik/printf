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
			if (flag_data->padding < 0)
				flag_data->padding = -j;
		}
		else if (flag_data->padding < 0)
				flag_data->padding = j;
	}
	if (flag_data->wildcard2 == TRUE && flag_data->precision < 0)
		flag_data->precision = va_arg(data->arg, int);
}

void handle_padding(t_flag_data *flag_data, char **str2)
{
	char	*s2;

	if (flag_data->padding <= (int)(ft_strlen(*str2)))
		return ;
	s2 = ft_strnew_c(flag_data->padding - ft_strlen(*str2), ' ');
	if (flag_data->minus == TRUE)
		ft_str_replace_back(str2, s2);
	else
		ft_str_replace_front(s2, str2);
	free(s2);
}

void handle_padding_c(t_flag_data *flag_data, char **str2)
{
	char	*s2;

	if (flag_data->padding <= 1)
		return ;
	s2 = ft_strnew_c(flag_data->padding - 1, ' ');
	if (flag_data->minus == TRUE)
		ft_str_replace_back(str2, s2);
	else
		ft_str_replace_front(s2, str2);
	free(s2);
}

void handle_precision(t_flag_data *flag_data, char **str)
{
	char	*s2;

	if (flag_data->precision > (int)(ft_strlen(*str)))
	{
		if (flag_data->zero == TRUE)
			flag_data->zero = FALSE;
		s2 = ft_strnew_c(flag_data->precision - (int)(ft_strlen(*str)), '0');
		ft_str_replace_front(s2, str);
	}
}

void handle_padding_num(t_flag_data *flag_data, char **str2)
{
	char	*s2;

	if (flag_data->zero == TRUE && flag_data->minus == FALSE && flag_data->precision != 0)
	{
		s2 = ft_strnew_c(flag_data->padding - ft_strlen(*str2), '0');
		ft_str_replace_front(s2, str2);
	}
	if (flag_data->padding <= (int)(ft_strlen(*str2)))
		return ;
	s2 = ft_strnew_c(flag_data->padding - ft_strlen(*str2), ' ');
	if (flag_data->minus == TRUE)
		ft_str_replace_back(str2, s2);
	else
		ft_str_replace_front(s2, str2);
	free(s2);
}

long long	handle_lh(t_data *data, t_flag_data *flag_data)
{
	long long i;

	if (flag_data->l_value == 2)
		i = va_arg(data->arg, long long);
	else if (flag_data->l_value == 1)
		i = va_arg(data->arg, long);
	else if (flag_data->h_value == 2)
		i = (char)(va_arg(data->arg, int));
	else if (flag_data->h_value == 1)
		i = (short)(va_arg(data->arg, int));
	else
		i = va_arg(data->arg, int);
	return (i);
}

long long	handle_lh_unsigned(t_data *data, t_flag_data *flag_data)
{
	long long i;

	if (flag_data->l_value == 2)
		i = va_arg(data->arg, unsigned long long);
	else if (flag_data->l_value == 1)
		i = va_arg(data->arg, unsigned long);
	else if (flag_data->h_value == 2)
		i = (unsigned char)(va_arg(data->arg, int));
	else if (flag_data->h_value == 1)
		i = (unsigned short)(va_arg(data->arg, int));
	else
		i = va_arg(data->arg, unsigned int);
	return (i);
}
