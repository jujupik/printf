#include "ft_printf.h"

char	*ft_strnew(size_t len)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

char	*ft_strdup(char *str)
{
	char	*result;
	size_t	len;
	size_t	i;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	result = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	result = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	return (result);
}

void	ft_str_replace_front(char *s2, char **s1)
{
	char	*result;

	result = ft_strjoin(s2, *s1);
	if (*s1 != NULL)
		free(*s1);
	*s1 = result;
}

void	ft_str_replace_back(char **s1, char *s2)
{
	char	*result;

	result = ft_strjoin(*s1, s2);
	if (*s1 != NULL)
		free(*s1);
	*s1 = result;
}
