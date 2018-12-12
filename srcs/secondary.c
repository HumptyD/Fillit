/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:37:11 by jlucas-l          #+#    #+#             */
/*   Updated: 2018/12/12 19:12:07 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt_t(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

char	**ft_create_map(int size)
{
	char	**res;
	int		i;

	if (!(res = (char **)malloc(sizeof(char *) * (size + 1))))
		display_error();
	i = 0;
	while (i < size)
	{
		if (!(res[i] = ft_strnew(size)))
			display_error();
		ft_memset(res[i++], '.', size);
	}
	res[i] = NULL;
	return (res);
}

void	free_map(char ***map, int size)
{
	while (size--)
	{
		free(map[0][size]);
		map[0][size] = NULL;
	}
	free(map[0]);
	map[0] = NULL;
}
