/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:16:05 by yogun             #+#    #+#             */
/*   Updated: 2022/08/23 14:14:37 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// This function is where the magic starts.
void start_game(char *map, t_game *game)
{
	int		fd;
	
	if (!ft_format_check(map))
		ft_error("Wrong map format!\n", &map);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error("No such file or directory!\n", &map);
	parse_map(fd, &map);
	ft_action(&map);
}
