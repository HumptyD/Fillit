/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:58:40 by jlucas-l          #+#    #+#             */
/*   Updated: 2018/12/12 17:42:43 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetr	tetrimino[TET_MAX];
	int		figures;

	if (argc != 2)
	{
		ft_putendl("usage: ./fillit input_file");
		return (1);
	}
	figures = ft_read_tetrimino(argv[1], tetrimino);
	ft_solve_tetrimino(tetrimino, figures);
	return (0);
}
