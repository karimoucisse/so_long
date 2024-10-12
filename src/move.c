/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:19:54 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/09 22:01:01 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

int	find_item(char **map, int *x, int *y, char item)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == item)
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_find_shark_dir(t_shark *shark, char dir)
{
	if (dir == 't' && shark->dir == 'r')
		shark->current_ptr = shark->top_right;
	if (dir == 't' && shark->dir == 'l')
		shark->current_ptr = shark->top_left;
	if (dir == 'b' && shark->dir == 'r')
		shark->current_ptr = shark->bottom_right;
	if (dir == 'b' && shark->dir == 'l')
		shark->current_ptr = shark->bottom_left;
	if (dir == 'l')
	{
		shark->current_ptr = shark->left;
		shark->dir = 'l';
	}
	if (dir == 'r')
	{
		shark->current_ptr = shark->right;
		shark->dir = 'r';
	}
}

void	ft_move(t_data *data, char dir)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	find_item(data->map->map, &x1, &y1, 'P');
	x2 = x1;
	y2 = y1;
	if (dir == 't')
		y2--;
	if (dir == 'b')
		y2++;
	if (dir == 'l')
		x2--;
	if (dir == 'r')
		x2++;
	if (data->map->map[y2][x2] == '1' || (data->map->map[y2][x2] == 'E'
		&& find_item(data->map->map, &x1, &y1, 'C')))
		return (ft_find_shark_dir(data->shark, dir));
	data->map->map[y1][x1] = '0';
	data->map->map[y2][x2] = 'P';
	data->move += 1;
	ft_find_shark_dir(data->shark, dir);
}

void	move_printer(t_data *data)
{
	if (data->move > data->prev_move)
	{
		ft_putnbr_fd(data->move, 1);
		if (data->move <= 1)
			write(1, " move\n", 6);
		else
			write(1, " moves\n", 7);
		data->prev_move = data->move;
	}
}
