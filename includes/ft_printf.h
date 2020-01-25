#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define BOOL char
# define TRUE 1
# define FALSE 0

# define PRINTF_BUFFER_SIZE 400

typedef struct	s_data
{
	va_list		arg;
	int			len;
	int			fd;
	char		*s_buffer;
	char		buffer[PRINTF_BUFFER_SIZE];
	size_t		size;
}				t_data;

t_data			create_data(char *s_buffer, int fd);
void			print_buffer(t_data *data);
void			add_char_to_buffer(t_data *data, char c);
void			add_str_to_buffer(t_data *data, char *str);
void			add_nb_char_to_buffer(t_data *data, char c, size_t nb);

typedef struct	s_flag_data
{
	BOOL	sharp;
	BOOL	zero;
	BOOL	minus;
	BOOL	plus;
	BOOL	space;
	BOOL	point;
	BOOL	wildcard1;
	BOOL	wildcard2;
	int		padding;
	int		precision;
	int		l_value;
	int		h_value;
}				t_flag_data;

typedef size_t	(* flag_funct)(t_flag_data *data, char *cmd, int i);
typedef void	(* t_convert_funct)(t_data *data, t_flag_data *flag_data);
t_flag_data		create_flag_data();
void			print_flag_data(t_flag_data *data);
void			read_cmd(char *cmd, t_data *data);
int				ft_printf(char *cmd, ...);
int				ft_sprintf(char *s_buffer, char *cmd, ...);
int				ft_fprintf(int fd, char *cmd, ...);
char			*ft_strnew(size_t len);
size_t			ft_strlen(char *str);
char			*ft_strdup(char *str);
char			*ft_strjoin(char *s1, char *s2);
void			ft_str_replace_front(char *s2, char **s1);
void			ft_str_replace_back(char **s1, char *s2);
void			ft_strcat(char *s1, char *s2);
void			ft_strncat(char *s1, char *s2, size_t len);
void			ft_target_strncat(char *s1, char *s2, size_t start, size_t len);
char			*ft_strcut(char **s1, char delim);
char			*ft_strnew_c(size_t len, char c);
void			handle_converter(t_data *data, t_flag_data *flag_data,
					char *cmd, size_t i);
void			converter_s(t_data *data, t_flag_data *flag_data);
void			converter_d(t_data *data, t_flag_data *flag_data);
void			converter_c(t_data *data, t_flag_data *flag_data);
void			converter_i(t_data *data, t_flag_data *flag_data);
void			converter_o(t_data *data, t_flag_data *flag_data);
void			converter_u(t_data *data, t_flag_data *flag_data);
void			converter_x(t_data *data, t_flag_data *flag_data);
void			converter_x_maj(t_data *data, t_flag_data *flag_data);
void			converter_p(t_data *data, t_flag_data *flag_data);
void			converter_percent(t_data *data, t_flag_data *flag_data);
void			converter_other(t_data *data, t_flag_data *flag_data, char c);
size_t			handle_flag(t_flag_data *data, char *cmd, size_t i);
size_t			flag_sharp(t_flag_data *data, char *cmd, int i);
size_t			flag_zero(t_flag_data *data, char *cmd, int i);
size_t			flag_minus(t_flag_data *data, char *cmd, int i);
size_t			flag_plus(t_flag_data *data, char *cmd, int i);
size_t			flag_space(t_flag_data *data, char *cmd, int i);
size_t			flag_point(t_flag_data *data, char *cmd, int i);
size_t			flag_digit(t_flag_data *data, char *cmd, int i);
size_t			flag_l(t_flag_data *data, char *cmd, int i);
size_t			flag_h(t_flag_data *data, char *cmd, int i);
size_t			flag_wildcard(t_flag_data *data, char *cmd, int i);
void			handle_wildcard(t_data *data, t_flag_data *flag_data);
void			handle_padding(t_flag_data *flag_data, char **str2);
void			handle_precision(t_flag_data *flag_data, char **str);
void			handle_padding_num(t_flag_data *flag_data, char **str2);
long long		handle_lh(t_data *data, t_flag_data *flag_data);
long long		handle_lh_unsigned(t_data *data, t_flag_data *flag_data);
void			handle_padding_c(t_flag_data *flag_data, char **str2);
int				ft_isdigit(int c);
char			*fill(char	*str, char c, int i);
int				nbr_len(long long n, int base);
char			*ft_itoa_base(long long n, int base);
char			*ft_itoa(long long n);
int				ft_atoi(const char *str);
int				ft_toupper(int c);
void			ft_str_toupper(char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strchr(const char *s1, char c);

#endif
