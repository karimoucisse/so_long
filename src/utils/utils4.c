/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:14:19 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/12 19:58:51 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../../libft/libft.h"
#include "../../gnl/get_next_line.h"

void	check_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		print_error("Bad extension => .ber");
	if (str[len - 1] != 'r' || str[len - 2] != 'e')
		print_error("Bad extension => .ber");
	if (str[len - 3] != 'b' || str[len - 4] != '.')
		print_error("Bad extension => .ber");
	if (str[len - 5] == '/' || str[len - 5] == ' ')
		print_error("Bad extension => .ber");
}

void	init_shark(t_shark *shark)
{
	shark->top_left = NULL;
	shark->top_right = NULL;
	shark->bottom_left = NULL;
	shark->bottom_right = NULL;
	shark->left = NULL;
	shark->right = NULL;
	shark->current_ptr = NULL;
}

int	ft_check_map_size_loop(t_map *stc_map, char *str, int fd)
{
	if (str == NULL)
		return (get_next_line(fd, 1), free(str), close(fd), 0);
	while (str)
	{
		stc_map->height++;
		if (str && (str[ft_strlen(str) - 1] == '\n'
				&& (((int)ft_strlen(str) - 1) != stc_map->width)))
			return (get_next_line(fd, 1), free(str), close(fd), 0);
		if (str && (str[ft_strlen(str) - 1] != '\n'
				&& (((int)ft_strlen(str)) != stc_map->width)))
			return (get_next_line(fd, 1), free(str), close(fd), 0);
		free(str);
		str = get_next_line(fd, 0);
	}
	return (1);
}
