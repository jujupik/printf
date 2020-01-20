#include "ft_printf.h"

typedef void (* convert_funct )(t_data *data, t_flag_data *flag_data);

void create_convert_funct_tab(convert_funct *tab)
{
	size_t i;

	i = 0;
	while (i < 128)
	{
		tab[i] = NULL;
		i++;
	}
	tab[0] = (void *)1;
	tab['s'] = converter_s;
	tab['c'] = converter_c;
	tab['d'] = converter_d;
	tab['i'] = converter_i;
	tab['o'] = converter_o;
	tab['u'] = converter_u;
	tab['x'] = converter_x;
	tab['X'] = converter_x_maj;
	tab['p'] = converter_p;
	tab['%'] = converter_percent;
}


void handle_converter(t_data *data, t_flag_data *flag_data, char *cmd, size_t i)
{
	static convert_funct tab[128] = {NULL}; //initialise un tableau set la premiere case a null

	if (tab[0] == NULL)
		create_convert_funct_tab(tab); //set le tab et les cases des converteurs (cf handle_flag)

	if (tab[(size_t)(cmd[i])] == NULL)
	{
		converter_other(data, flag_data, cmd[i]); //applique les flags si converteur NULL(donc inexistant ou pas gere)
	}
	else
	{
		tab[(size_t)(cmd[i])](data, flag_data); //execute la fonction du converteur correspondant
	}
}
