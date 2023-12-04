#include "cub3d.h"

int	is_it_ws(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	word_counter(const char *str)
{
	int	count;
	int	i;
	int	flag;

	count = 0;
	i = 0;
	flag = 1;
	while (str[i])
	{
		if (!is_it_ws(str[i]) && str[i] != ',' && flag == 1)
		{
			count++;
			flag = 0;
		}
		else if (is_it_ws(str[i]) || str[i] == ',')
			flag = 1;
		i++;
	}
	return (count);
}

int	word_len(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (is_it_ws(str[i]) || str[i] == ',')
		i++;
	while (!is_it_ws(str[i]) && str[i] != ',' && str[i])
	{
		i++;
		count++;
	}
	return (count);
}

char	*stringer(const char *src)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * word_len(src) + 1);
	i = 0;
	while (*src && !is_it_ws(*src) && *src != ',')
	{
		ret[i] = *(src++);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_split_special(const char *s)
{
	char	**result;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	size = word_counter(s);
	result = malloc(sizeof(char *) * (size + 1));
	if (result == NULL)
		return (0);
	i = 0;
	j = 0;
	while (j < size && s[i])
	{
		while (s[i] && is_it_ws(s[i]) || s[i] == ',')
			i++;
		result[j] = stringer(&s[i]);
		while (s[i] && !is_it_ws(s[i]) && s[i] != ',')
			i++;
		j++;
	}
	result[j] = NULL;
	return (result);
}
