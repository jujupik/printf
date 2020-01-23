#include "ft_printf.h"

size_t flag_sharp(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->sharp = TRUE;
	return (1);
}

size_t flag_zero(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	if (data->point == FALSE)
		data->zero = TRUE;
	else
		data->precision = 0;
	return (1);
}

size_t flag_minus(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->minus = TRUE;
	data->zero = FALSE;
	return (1);
}

size_t flag_plus(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->plus = TRUE;
	return (1);
}

size_t flag_space(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->space = TRUE;
	return (1);
}

size_t flag_point(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->point = TRUE;
	data->zero = FALSE;
	return (1);
}

size_t flag_digit(t_flag_data *data, char *cmd, int i)
{
	char *actual_cmd;

	actual_cmd = &(cmd[i]);
	int value = ft_atoi(actual_cmd);
	if (data->point == FALSE)
		data->padding = value;
	else
	{
		data->precision = value;
		data->zero = FALSE;
	}
	return (nbr_len(value, 10));
}

size_t flag_wildcard(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	if (data->point == FALSE)
	{
		data->wildcard1 = TRUE;
		data->padding = -128;
	}
	else
	{
		data->wildcard2 = TRUE;
		data->precision = -128;
		data->zero = FALSE;
	}
	return (1);
}

size_t flag_l(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->l_value++;
	return (1);
}

size_t flag_h(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->h_value++;
	return (1);
}
