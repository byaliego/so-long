/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:07:54 by yogun             #+#    #+#             */
/*   Updated: 2022/08/26 14:37:06 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_so_long.h"

void	ft_loop(t_game *map)
{
	map->players++;
	if (map->players == 40 || map->players == 160 || map->players == 280)
	{
		map->enemy = map->enemy1;
		map->item = map->item1;
	}
	if (map->players == 80 || map->players == 200 || map->players == 320)
	{
		map->enemy = map->enemy2;
		map->item = map->item2;
	}
	if (map->players == 120 || map->players == 240 || map->players == 360)
	{
		map->enemy = map->enemy0;
		map->item = map->item0;
	}
	if (map->gameover == 0 && map->players == 200)
		map->player = map->player0;
	if (map->gameover == 0 && map->players == 300)
		map->player = map->player1;
	if (map->gameover == 0 && map->players == 400)
		map->player = map->player2;
	if (map->players == 410)
		map->players = 1;
}

int	ft_game(t_game *map)
{
	char	*s;

	ft_loop(map);
	if (!map->gameover)
		ft_enemy(map);
	ft_map_render(map, 0, 0, -1);
	s = ft_itoa(map->steps);
	mlx_string_put(map->mlx, map->win, 20, 20, 0x00FF0000, s);
	free(s);
	return (1);
}
