/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:19:44 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/12 19:46:15 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"

int	ft_is_map_valid(t_data *data)
{
	int	i;

	i = 0;
	if (!ft_check_map_size(data->map))
		free_struct(data, "Error: invalid Map");
	if (!ft_create_map(data->map))
		free_struct(data, "Error: Map is not rectangle");
	data->map->items = ft_check_map_content(data->map->map);
	if (!data->map->items)
		free_struct(data, "Error: check Map content");
	if (!ft_is_map_rectangle(data->map))
		free_struct(data, "Error: Map is not rectangle or surround with 1");
	if (!floodfill(data->map, 'N'))
		free_struct(data, "Unplayable Map");
	return (1);
}

int	ft_check_map_size(t_map *stc_map)
{
	char	*str;
	int		fd;

	fd = ft_open_file(stc_map->file);
	if (fd == -1)
	{
		free(stc_map);
		exit (0);
	}
	str = get_next_line(fd, 0);
	if (str == NULL)
		return (close(fd), 0);
	stc_map->height = 0;
	stc_map->width = ft_strlen(str) - 1;
	if (!ft_check_map_size_loop(stc_map, str, fd))
		return (0);
	if (stc_map->height < 3)
		return (get_next_line(fd, 1), close(fd), 0);
	return ((close(fd)), 1);
}

int	ft_create_map(t_map *stc_map)
{
	char	*str;
	int		fd;

	stc_map->map = malloc(sizeof(char *) * (stc_map->height + 1));
	if (!stc_map)
		return (0);
	fd = ft_open_file(stc_map->file);
	if (fd == -1)
		return (0);
	str = get_next_line(fd, 0);
	if (!str)
		return (close(fd), 0);
	stc_map->map[0] = ft_substr(str, 0, stc_map->width);
	if (!(stc_map->map[0]))
		return (close(fd), 0);
	if (!create_map_loop(stc_map, str, fd))
		return (close(fd), 0);
	return (close(fd), 1);
}

int	ft_check_map_content(char **map)
{
	int	e;
	int	c;
	int	p;

	e = 0;
	c = 0;
	p = 0;
	if (!check_map_content_loop(map, &e, &c, &p))
		return (0);
	if (e != 1 || p != 1 || c == 0)
		return (0);
	return (c);
}

int	ft_is_map_rectangle(t_map *stc_map)
{
	int		i;
	char	**map;

	i = 1;
	map = stc_map->map;
	if (!check_wall(map[0]))
		return (0);
	if (!check_wall(map[stc_map->height - 1]))
		return (0);
	while (i < stc_map->height - 1)
	{
		if (map[i][0] != '1' || map[i][stc_map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
