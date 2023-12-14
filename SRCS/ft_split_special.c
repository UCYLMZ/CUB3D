/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_special.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:02:16 by mdiraga           #+#    #+#             */
/*   Updated: 2023/12/13 03:02:17 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_it_ws(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

char	**handle_texture(const char *s, t_data *map_data)
{
	char	**result;
	char	**raw;
	int		i;

	result = malloc(sizeof(char *) * 3);
	if (!result)
		allocation_exit(map_data);
	raw = ft_split(s, ' ');
	if (!raw[0][0] || !raw[1][0])
	{
		free_double_char(raw);
		free(result);
		wrong_map_exit(map_data, 23);
	}
	result[0] = ft_strdup(raw[0]);
	free_double_char(raw);
	result[2] = NULL;
	i = 0;
	while (s[i] && s[i] != '.' && s[i + 1] != '/')
		i++;
	result[1] = ft_strtrim(&s[i], "\n");
	return (result);
}

char	**handle_fc(const char *s, t_data *map_data)
{
	char	**result;
	char	**raw;
	char	**first_index;
	int		i;

	result = malloc(sizeof(char *) * 5);
	if (!result)
		allocation_exit(map_data);
	raw = ft_split(s, ',');
	i = -1;
	while (raw[++i]);
	if (i != 3)
	{
		free(result);
		wrong_map_exit(map_data, 21);
	}
	first_index = ft_split(raw[0], ' ');
	result[0] = ft_strdup(first_index[0]);
	result[1] = ft_strdup(first_index[1]);
	result[2] = ft_strtrim(raw[1], " \n");
	result[3] = ft_strtrim(raw[2], " \n");
	result[4] = NULL;
	free_double_char(raw);
	free_double_char(first_index);
	return (result);
}

char	**ft_split_special(const char *s, t_data *map_data)
{
	char	**result;

	if (!s)
		return (NULL);
	if ((s[0] == 'F' || s[0] == 'C') && s[1] == ' ')
		result = handle_fc(s, map_data);
	else
		result = handle_texture(s, map_data);

	// int i = -1;
	// while (result[++i])
	// 	printf("#%s#\n", result[i]);
	return (result);
}
