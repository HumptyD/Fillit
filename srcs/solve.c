/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:07:19 by jlucas-l          #+#    #+#             */
/*   Updated: 2018/12/12 19:11:56 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_tetri(t_tetr tetri, char **map, int i, int j)
{
	int block;

	block = 4;
	while (block--)
		map[tetri.y[block] + i][tetri.x[block] + j] = '.';
}

void	place_tetri(t_tetr tetri, char **map, int i, int j)
{
	int block;

	block = 4;
	while (block--)
		map[tetri.y[block] + i][tetri.x[block] + j] = tetri.letter;
}

int		check_place(t_tetr tetri, char **map, int i, int j)
{
	int block;

	block = 4;
	while (block--)
	{
		if (map[tetri.y[block] + i][tetri.x[block] + j] != '.')
			return (1);
	}
	return (0);
}

int		solve_algo(t_tetr tetri[], t_msize map_struct, int n, int id)
{
	int i;
	int j;

	i = 0;
	while (i + tetri[id].height <= map_struct.map_size)
	{
		j = 0;
		while (j + tetri[id].width <= map_struct.map_size)
		{
			if (!check_place(tetri[id], map_struct.map, i, j))
			{
				place_tetri(tetri[id], map_struct.map, i, j);
				if (id == n - 1 || solve_algo(tetri, map_struct, n, id + 1))
					return (1);
				else
					remove_tetri(tetri[id], map_struct.map, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_solve_tetrimino(t_tetr tetrimino[], int n)
{
	t_msize	map_struct;
	int		id;

	map_struct.map_size = ft_sqrt_t(n * 4);
	map_struct.map = ft_create_map(map_struct.map_size);
	id = 0;
	while (!solve_algo(tetrimino, map_struct, n, id))
	{
		free_map(&map_struct.map, map_struct.map_size);
		map_struct.map_size++;
		map_struct.map = ft_create_map(map_struct.map_size);
	}
	display_map(map_struct.map);
	free_map(&map_struct.map, map_struct.map_size);
}
