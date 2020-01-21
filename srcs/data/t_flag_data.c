#include "ft_printf.h"

t_flag_data	create_flag_data(void)
{
	t_flag_data	result;

	// - set flag true si on l'a et un nb
	result.sharp = FALSE;
	result.zero = FALSE;
	result.minus = FALSE;
	result.plus = FALSE;
	result.space = FALSE;
	result.point = FALSE;
	result.wildcard1 = FALSE;
	result.wildcard2 = FALSE;
	result.padding = 0;
	result.precision = 0;
	result.l_value = 0;
	result.h_value = 0;
	return (result);
}

/** fonction test si on recup bien les flags
**void print_flag_data(t_flag_data *data)
**{
**	printf("-------------\n");
**	printf("sharp = %s\n", (data->sharp == TRUE ? "true" : "false"));
**	printf("zero = %s\n", (data->zero == TRUE ? "true" : "false"));
**	printf("minus = %s\n", (data->minus == TRUE ? "true" : "false"));
**	printf("plus = %s\n", (data->plus == TRUE ? "true" : "false"));
**	printf("space = %s\n", (data->space == TRUE ? "true" : "false"));
**	printf("point = %s\n", (data->point == TRUE ? "true" : "false"));
**	printf("padding = %d\n", data->padding);
**	printf("precision = %d\n", data->precision);
**	printf("l_value = %d\n", data->l_value);
**	printf("h_value = %d\n", data->h_value);
**	printf("-------------\n");
**}
**/
