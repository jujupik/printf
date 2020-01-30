/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:02:18 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/26 17:02:20 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_convert_funct_tab(t_convert_funct *tab)
{
	size_t	i;

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

void	handle_converter(t_data *data, t_flag_data *flag_data,
			char *cmd, size_t i)
{
	static t_convert_funct	tab[128] = {NULL};

	if (tab[0] == NULL)
		create_convert_funct_tab(tab);
	if (cmd[i] == '\0')
		return ;
	if (tab[(size_t)(cmd[i])] == NULL)
		converter_other(data, flag_data, cmd[i]);
	else
		tab[(size_t)(cmd[i])](data, flag_data);
}
