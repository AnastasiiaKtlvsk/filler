/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cranium.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:12:32 by akotilie          #+#    #+#             */
/*   Updated: 2018/06/09 15:12:34 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRANIUM_H
# define CRANIUM_H
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
#include <stdio.h>

typedef	struct	s_p
{
	int		*x;
	int		*y;
}				t_p;

typedef struct	s_sh
{
	t_p		*p;
	int 	c; //count
	int		x;
	int		y;
	int		r_x; //sdvig po x
	int		r_y;
	char 	**sm;
}				t_sh;

typedef struct	t_ps
{
	t_p		*ap; //available points
	int  	c;
	int 	r; //result
}				t_ps;

typedef struct	s_map
{
	char	**map;
	int		x;
	int		y;
	int		l;	//letter
	int 	el; //enemy letter
	t_p		*p; //enemy points
	int 	ce; //count enemies
	t_sh	*sh;
	t_ps	*ps;
}				t_map;

void	read_specification(t_map** tm, int i);
void	create_map(t_map** tm);
void	free_map(t_map** tm);
void	find_enemy_points(t_map** tm);

char*	delete_last_char(char **s);
char*	delete_begin(char **s);
int		index_first_char(char **s, char c);

void	find_shape_points(t_map** tm, int c, int j);
void	create_shape(t_map** tm);
void	read_shape(t_map** tm);

void	create_positions_arr(t_map** tm);
void	find_best_point(t_map** tm);
void	positions(t_map** tm, int j, int p, int i);
int		find_distance_in_square(int x1, int y1, int x2, int y2);

void print_map(t_map** tm);
void	print_shape(t_map** tm);




#endif