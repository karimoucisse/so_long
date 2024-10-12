/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:19:47 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/12 18:51:22 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

void	filler(t_map *map, int x, int y, char newclr)
{
	if (map->map[x][y] != '0' && map->map[x][y] != 'C')
		return ;
	map->map[x][y] = newclr;
	if (x - 1 >= 0)
		filler(map, x - 1, y, newclr);
	if (y + 1 < map->width)
		filler(map, x, y + 1, newclr);
	if (x + 1 < map->height)
		filler(map, x + 1, y, newclr);
	if (y - 1 >= 0)
		filler(map, x, y - 1, newclr);
}

int	floodfill(t_map *map, char newclr)
{
	int		x;
	int		y;
	t_map	*map_cpy;

	y = 0;
	x = 0;
	map_cpy = ft_map_cpy(map);
	if (!map_cpy)
		return (0);
	find_item(map_cpy->map, &y, &x, 'P');
	map_cpy->map[x][y] = '0';
	if ('0' == newclr)
		return (free_chars(map_cpy->map), free(map_cpy), 0);
	filler(map_cpy, x, y, newclr);
	if (!ft_check_flood_fill(map_cpy->map))
		return (free_chars(map_cpy->map), free(map_cpy), 0);
	return (free_chars(map_cpy->map), free(map_cpy), 1);
}

int	ft_check_flood_fill(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	find_item(map, &i, &j, 'E');
	if ((map[j + 1][i] != 'N' && map[j - 1][i] != 'N')
		&& (map[j][i + 1] != 'N' && map[j][i - 1] != 'N'))
		return (0);
	return (1);
}

t_map	*ft_map_cpy(t_map *map)
{
	t_map	*map_cpy;

	map_cpy = malloc(sizeof(t_map));
	if (!map_cpy)
		return (0);
	map_cpy->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map_cpy->map)
	{
		free(map_cpy);
		return (0);
	}
	map_cpy->height = map->height;
	map_cpy->width = map->width;
	map_cpy->items = map->items;
	map_cpy->file = NULL;
	if (!map_cpy_loop(map_cpy, map))
		return (0);
	return (map_cpy);
}
