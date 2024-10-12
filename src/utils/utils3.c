/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:20:05 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/12 17:27:24 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../../libft/libft.h"

int	check_map_content_loop(char **map, int *e, int *c, int *p)
{
	int	i;

	while (*map)
	{
		i = 0;
		while ((*map)[i])
		{
			if ((*map)[i] == 'E')
				*e += 1;
			if ((*map)[i] == 'C')
				*c += 1;
			if ((*map)[i] == 'P')
				*p += 1;
			if (!ft_strchr("ECP01", (*map)[i]))
				return (0);
			i++;
		}
		map++;
	}
	return (1);
}

void	add_wall_and_items_loop(t_data *data, int i, int x, int y)
{
	int	j;

	j = 0;
	while (data->map->map[i][j])
	{
		if (data->map->map[i][j] == '1')
			img_to_win(data, data->wall_ptr, j, i);
		if (data->map->map[i][j] == 'C')
			img_to_win(data, data->items_ptr, j, i);
		if (data->map->map[i][j] == '0')
			img_to_win(data, data->blank_ptr, j, i);
		if (data->map->map[i][j] == 'P')
			img_to_win(data, data->shark->current_ptr, j, i);
		if (data->map->map[i][j] == 'E'
			&& !find_item(data->map->map, &x, &y, 'C'))
			img_to_win(data, data->exit_green_ptr, j, i);
		if (data->map->map[i][j] == 'E'
			&& find_item(data->map->map, &x, &y, 'C'))
			img_to_win(data, data->exit_red_ptr, j, i);
		j++;
	}
}

int	map_cpy_loop(t_map *map_cpy, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		map_cpy->map[i] = ft_strdup(map->map[i]);
		if (!map_cpy->map[i])
		{
			free_chars(map_cpy->map);
			free(map_cpy);
			return (0);
		}
		i++;
	}
	map_cpy->map[i] = NULL;
	return (1);
}

int	check_img_ptr(t_data *data)
{
	int	error;

	error = 0;
	if (!data->shark->left || !data->shark->right || !data->shark->top_left)
		error = 1;
	if (!data->shark->top_right || !data->shark->bottom_left)
		error = 1;
	if (!data->items_ptr || !data->blank_ptr)
		error = 1;
	if (!data->exit_green_ptr || !data->exit_red_ptr)
		error = 1;
	if (error)
	{
		destroy_img(data);
		free_struct(data, "Error: Images loading");
	}
	return (1);
}

void	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->wall_ptr = NULL;
	data->items_ptr = NULL;
	data->blank_ptr = NULL;
	data->exit_red_ptr = NULL;
	data->exit_green_ptr = NULL;
	data->map = NULL;
	data->shark = NULL;
}
