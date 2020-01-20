#include "ft_printf.h"
// [Ce que l'on veut obtenir] - [le nom de la fonction] - [les parametres a donner pour avoir ce qu'on veut a la fin]
// [char *]						[ft_strnew]				  [(size_t len)]
// Creer une nouvelle chaine de caracteres de longueur len
char *ft_strnew(size_t len)
{
	char *result;
	size_t i;

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

// Compte la longueur d'une chaine de caracteres
size_t ft_strlen(char *str)
{
	size_t result;

	if (str == NULL)
		return (0);

	result = 0;
	while (str[result] != '\0')
		result++;

	return (result);
}

//Creer une copie de la chaine de caracteres str
char *ft_strdup(char *str)
{
	char *result;
	size_t len;
	size_t i;

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

// rajoute s2 a s1 et renvoi le total
char *ft_strjoin(char *s1, char *s2)
{
	char *result;
	size_t i;
	size_t j;

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

//Rajouter s2 devant s1 et de remplacer s1 avec la nouvelle version
void ft_str_replace_front(char *s2, char **s1)
{
	char *result;

	result = ft_strjoin(s2, *s1);
	if (*s1 != NULL)
		free(*s1);
	*s1 = result;
}

//Rajouter s2 derriere s1 et de remplacer s1 avec la nouvelle version
void ft_str_replace_back(char **s1, char *s2)
{
	char *result;

	result = ft_strjoin(*s1, s2);
	if (*s1 != NULL)
		free(*s1);
	*s1 = result;
}

void ft_strcat(char *s1, char *s2)
{
	ft_strncat(s1, s2, ft_strlen(s2));
}

void ft_strncat(char *s1, char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = ft_strlen(s1);
	j = 0;
	while (j < len)
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
}


int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strchr(const char *s1, char c)
{
	unsigned int i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_strcut(char **s1, char delim)
{
	char *tmp;
	char *result;
	size_t len;
	// size_t i;

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

char	*fill(char	*str, char c, int i)
{
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = c;
		i--;
	}
	return (str);
}
