/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:41:14 by jlucas-l          #+#    #+#             */
/*   Updated: 2018/12/12 19:12:04 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"

# define TET_MAX 26

typedef	struct		s_tetr
{
	int				x[4];
	int				y[4];
	int				height;
	int				width;
	char			letter;
}					t_tetr;

typedef struct		s_msize
{
	int				map_size;
	char			**map;
}					t_msize;

int					ft_read_tetrimino(char *file, t_tetr tetrimino[]);
int					is_valid(char *buf, int size);
void				display_error(void);
int					display_map(char **map);
int					ft_sqrt_t(int n);
void				ft_solve_tetrimino(t_tetr tetrimino[], int n);
char				**ft_create_map(int size);
void				free_map(char ***map, int size);

#endif
