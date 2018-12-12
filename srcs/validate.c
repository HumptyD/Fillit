/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:48:48 by jlucas-l          #+#    #+#             */
/*   Updated: 2018/12/12 16:29:21 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_tetri(char *buf)
{
	int		connect;
	int		i;
	int		block;

	i = -1;
	connect = 0;
	block = 0;
	while (buf[++i])
	{
		if (buf[i] == '#')
		{
			if (i < 14 && buf[i + 5] == '#')
				connect++;
			if (i > 4 && buf[i - 5] == '#')
				connect++;
			if (i > 0 && buf[i - 1] == '#')
				connect++;
			if (i < 19 && buf[i + 1] == '#')
				connect++;
			block++;
		}
	}
	if (block != 4)
		return (0);
	return (connect);
}

int		valid_char(char *buf, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (((i + 1) % 5 == 0) && buf[i] != '\n')
			return (1);
		if (((i + 1) % 5 != 0) && buf[i] != '.'
				&& buf[i] != '#' && i != 20)
			return (1);
		if (i == 20 && buf[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int		is_valid(char *buf, int size)
{
	int		connect;

	if (valid_char(buf, size))
		return (1);
	connect = valid_tetri(buf);
	if (connect != 6 && connect != 8)
		return (1);
	return (0);
}
