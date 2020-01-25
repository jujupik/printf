#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	result;

	if (str == NULL)
		return (0);
	result = 0;
	while (str[result] != '\0')
		result++;
	return (result);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_strchr(const char *s1, char c)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcut(char **s1, char delim)
{
	char	*tmp;
	char	*result;
	size_t	len;

	tmp = *s1;
	len = 0;
	while (tmp[len] != '\0' && tmp[len] != delim)
		len++;
	result = ft_strnew(len);
	ft_strncat(result, tmp, len - 1);
	*s1 = ft_strnew(ft_strlen(tmp) - len);
	ft_strcat(*s1, &(tmp[len + 1]));
	free(tmp);
	return (result);
}
