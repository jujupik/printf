#include "ft_printf.h"

void	converter_percent(t_data *data, t_flag_data *flag_data)
{
	char	*str;

	handle_wildcard(data, flag_data);
	str = ft_strdup("%");
	handle_padding(flag_data, &str);
	add_str_to_buffer(data, str);
	free(str);
}

void	converter_other(t_data *data, t_flag_data *flag_data, char c)
{
	char	str[2];

	(void)flag_data;
	str[0] = c;
	str[1] = '\0';
	add_str_to_buffer(data, str);
}
