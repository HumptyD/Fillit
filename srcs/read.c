/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:34:52 by jlucas-l          #+#    #+#             */
/*   Updated: 2018/12/12 16:30:30 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_width_height(t_tetr *tetri, int block)
{
	int		max[2];
	int		min[2];
	int		n;

	n = block;
	max[0] = tetri->x[0];
	max[1] = tetri->y[0];
	min[0] = tetri->x[0];
	min[1] = tetri->y[0];
	while (block--)
	{
		max[0] = (tetri->x[block] > max[0]) ? tetri->x[block] : max[0];
		max[1] = (tetri->y[block] > max[1]) ? tetri->y[block] : max[1];
		min[0] = (tetri->x[block] < min[0]) ? tetri->x[block] : min[0];
		min[1] = (tetri->y[block] < min[1]) ? tetri->y[block] : min[1];
	}
	tetri->width = max[0] - min[0] + 1;
	tetri->height = max[1] - min[1] + 1;
	while (n--)
	{
		tetri->x[n] -= min[0];
		tetri->y[n] -= min[1];
	}
}

t_tetr	ft_get_coords(char *buf, int n)
{
	int		i;
	int		block;
	t_tetr	tetri;

	i = -1;
	block = 0;
	while (buf[++i])
	{
		if (buf[i] == '#')
		{
			tetri.x[block] = i % 5;
			tetri.y[block] = i / 5;
			block++;
		}
	}
	tetri.letter = n + 65;
	ft_width_height(&tetri, block);
	return (tetri);
}

int		ft_read_tetrimino(char *file, t_tetr tetrimino[])
{
	int		ret[3];
	int		fd;
	char	buf[22];

	fd = open(file, O_RDONLY);
	ret[2] = 0;
	while ((ret[0] = read(fd, buf, 21)))
	{
		buf[ret[0]] = '\0';
		ret[2]++;
		if ((ret[0] != 20 && ret[0] != 21) || ret[2] > TET_MAX
				|| is_valid(buf, ret[0]))
			display_error();
		tetrimino[ret[2] - 1] = ft_get_coords(buf, ret[2] - 1);
		ret[1] = ret[0];
	}
	if (ret[1] != 20)
		display_error();
	return (ret[2]);
}
