#include "ft_printf.h"

typedef size_t (* flag_funct )(t_flag_data *data, char *cmd, int i);

void create_flag_funct_tab(flag_funct *tab)
{
	size_t i;

	i = 0;
	while (i < 128)
	{
		tab[i] = NULL;
		i++;
	}
	tab[0] = (void *)1;
	tab['#'] = flag_sharp;
	tab['0'] = flag_zero;
	tab['-'] = flag_minus;
	tab['+'] = flag_plus;
	tab[' '] = flag_space;
	tab['.'] = flag_point;
	tab['1'] = flag_digit;
	tab['2'] = flag_digit;
	tab['3'] = flag_digit;
	tab['4'] = flag_digit;
	tab['5'] = flag_digit;
	tab['6'] = flag_digit;
	tab['7'] = flag_digit;
	tab['8'] = flag_digit;
	tab['9'] = flag_digit;
	tab['l'] = flag_l;
	tab['h'] = flag_h;
	tab['*'] = flag_wildcard;
}

size_t handle_flag(t_flag_data *data, char *cmd, size_t i)
{
	size_t j;
	// on demande un espace dans la bibliotheque de 128 cases et on set la permiere a NULL
	static flag_funct tab[128] = {NULL};

	// Si la premiere est a NULL on execute create (qui set la totalité a null et set les flags demandé et le premier a 1)
	if (tab[0] == NULL)
		create_flag_funct_tab(tab);

	// Tant que le tableau a la case "cmd[i]" est un flag
	// on execute la fonction qui correspond a ce char la puis on avance sur le char suivant
	j = 1;
	while (tab[(size_t)(cmd[i + j])] != NULL)
		j += tab[(size_t)(cmd[i + j])](data, cmd, i + j);
	return (j);
}
