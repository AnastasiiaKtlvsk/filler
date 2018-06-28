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
	int		*f_c; //fit coefficien -index in array of coefficients = index in array of poins that fits for place
	t_p		*f_p; //array of higher left points of place where can be shape
}				t_sh;

typedef struct	t_ps
{
	t_p		*p;
	int  	*c;
}

typedef struct	s_map
{
	char	**map;
	int		x;
	int		y;
	int		l; //letter
}				t_map;

void	read_specification(t_map** tm);
void	create_map(t_map** tm);
void	free_map(t_map** tm);
void	create_map(t_map** tm);

char*	delete_last_char(char **s);
char*	delete_begin(char **s);
int		index_first_char(char **s, char c);

void	find_shape_points(t_sh** sh, int c, int j);
void	create_shape(t_sh** sh);
void	free_shape(t_sh** sh);


void print_map(t_map** tm);
void	print_shape(t_sh** sh);




#endif