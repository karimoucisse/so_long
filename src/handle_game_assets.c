/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game_assets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:19:50 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/12 15:11:59 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

int	init_mlx(t_data *data)
{
	int		w;
	int		h;

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		free_struct(data, "Error: mlx_init()");
	data->blank_ptr = xpm_to_img(data, "assets/water.xpm", &w, &h);
	data->items_ptr = xpm_to_img(data, "assets/fish.xpm", &w, &h);
	data->exit_red_ptr = xpm_to_img(data, "assets/exit_red.xpm", &w, &h);
	data->exit_green_ptr = xpm_to_img(data, "assets/exit_green.xpm", &w, &h);
	data->wall_ptr = xpm_to_img(data, "assets/wall.xpm", &w, &h);
	data->win_ptr = mlx_new_window(data->mlx_ptr, w * data->map->width,
			h * data->map->height, "Shark attack");
	if (!data->win_ptr)
		free_struct(data, "Error: int win_ptr");
	init_shark_img(data, w, h);
	check_img_ptr(data);
	data->width = w;
	data->height = h;
	data->move = 0;
	data->prev_move = 0;
	return (1);
}

void	init_shark_img(t_data *data, int w, int h)
{
	data->shark->left = xpm_to_img(data, "assets/shark_left.xpm", &w, &h);
	data->shark->right = xpm_to_img(data, "assets/shark_right.xpm", &w, &h);
	data->shark->top_left = xpm_to_img(data,
			"assets/shark_top_left.xpm", &w, &h);
	data->shark->top_right = xpm_to_img(data,
			"assets/shark_top_right.xpm", &w, &h);
	data->shark->bottom_left = xpm_to_img(data,
			"assets/shark_bottom_left.xpm", &w, &h);
	data->shark->bottom_right = xpm_to_img(data,
			"assets/shark_bottom_right.xpm", &w, &h);
	data->shark->current_ptr = data->shark->right;
	data->shark->dir = 'r';
}

int	ft_load_game_assets(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!find_item(data->map->map, &x, &y, 'C')
		&& !find_item(data->map->map, &x, &y, 'E'))
	{
		move_printer(data);
		on_destroy(data);
	}
	add_wall_and_items(data);
	return (1);
}

int	add_wall_and_items(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (data->map->map[i])
	{
		add_wall_and_items_loop(data, i, x, y);
		i++;
	}
	move_printer(data);
	return (1);
}

int	key_hook(int key, t_data *data)
{
	if (key == 65307)
		on_destroy(data);
	if (key == 65362 || key == 119)
		ft_move(data, 't');
	if (key == 65364 || key == 115)
		ft_move(data, 'b');
	if (key == 65361 || key == 97)
		ft_move(data, 'l');
	if (key == 65363 || key == 100)
		ft_move(data, 'r');
	return (0);
}
