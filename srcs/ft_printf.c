#include "ft_printf.h"

void read_cmd(char *cmd, t_data *data)
{
	size_t i;
	t_flag_data flag_data;

	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '%')
		{
			flag_data = create_flag_data(); //structure pour les flags
			i += handle_flag(&flag_data, cmd, i); //on recupere les flags dans un tab et on avance du nb lu
			handle_converter(data, &flag_data, cmd, i); //on execute le converter avec les flags recuperes plus haut
		}
		else
		{
			add_char_to_buffer(data, cmd[i]); //on rajoute le reste au buffer
		}
		i++;
	}
}

int ft_printf(char *cmd, ... )
{
	t_data data; // on declare la structure data

	if (cmd == NULL) // si on a pas de param on renvoi -1
		return (-1);

	data = create_data(NULL, 1); //on initialise data avec un buffer NULL et un fd a 1
	va_start(data.arg, cmd); //on recupere nos arguments passes dans les ... (param variatiques) malloc dans arg

	read_cmd(cmd, &data); //on lance la fonction qui va faire printf et le mettre dans le buffer

	print_buffer(&data); //on print le buffer
	va_end(data.arg); //ferme la liste des arg (eviter leaks)
	return (data.len); //on return le nombre de char du buffer
}

int ft_sprintf(char *s_buffer, char *cmd, ... )
{
	t_data data;

	if (cmd == NULL || s_buffer == NULL)
		return (-1);

	data = create_data(s_buffer, -1);
	va_start(data.arg, cmd);

	read_cmd(cmd, &data);

	print_buffer(&data);
	va_end(data.arg);
	return (data.len);
}

int ft_fprintf(int fd, char *cmd, ... )
{
	t_data data;

	if (cmd == NULL || (fd < 1))
		return (-1);

	data = create_data(NULL, fd);
	va_start(data.arg, cmd);

	read_cmd(cmd, &data);

	print_buffer(&data);
	va_end(data.arg);
	return (data.len);
}
