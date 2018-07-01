/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:52:44 by akotilie          #+#    #+#             */
/*   Updated: 2018/06/09 15:52:47 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cranium.h"

void	create_shape(t_map** tm)
{
	char	*sp;
	char	**sizes;
	int		i;

	(*tm)->sh = (t_sh*)ft_memalloc(sizeof(t_sh));
	get_next_line(0, &sp);
	sizes = ft_strsplit(sp, ' ');
	free(sp);
	(*tm)->sh->y = ft_atoi(sizes[1]);
	(*tm)->sh->x = ft_atoi(delete_last_char(&(sizes[2])));
	i = -1;
	while (++i < 3)
		free(sizes[i]);
	free(sizes);
	read_shape(tm);
	find_shape_points(tm, 0, -1);
}

void	read_shape(t_map** tm)
{
	int j;
	int i;

	j = -1;
	(*tm)->sh->sm = (char**)ft_memalloc(sizeof(char*) * (*tm)->sh->y);
	while (++j < (*tm)->sh->y)
	{
		get_next_line(0, &((*tm)->sh->sm[j]));
		i = -1;
		while ((*tm)->sh->sm[j][++i])
		{
			if ((*tm)->sh->sm[j][i] == '*')
				(*tm)->sh->c++;
		}
	}
}

void	find_shape_points(t_map** tm, int c, int j)
{
	int		i;

	(*tm)->sh->p = (t_p*)ft_memalloc(sizeof(t_p));
	(*tm)->sh->p->x = (int*)ft_memalloc(sizeof(int) * (*tm)->sh->c);
	(*tm)->sh->p->y = (int*)ft_memalloc(sizeof(int) * (*tm)->sh->c);
	//printf("(*tm)->sh->p->y %p\n", (*tm)->sh->p->y);
	while (++j < (*tm)->sh->y)
	{
		i = -1;
		while ((*tm)->sh->sm[j][++i])
		{			
			if ((*tm)->sh->sm[j][i] == '*')
			{
				(c == 0) ? (*tm)->sh->r_y = j : 0;
				(c == 0) ? (*tm)->sh->r_x = i : 0;
				(*tm)->sh->p->y[c] = j - (*tm)->sh->r_y;
				(*tm)->sh->p->x[c++] = i - (*tm)->sh->r_x;
			}
		}
	}
}


void	print_shape(t_map** tm)
{
	int j = -1;
	int i = -1;

	printf("Shape X = %i\n", (*tm)->sh->x);
	printf("Shape Y = %i\n", (*tm)->sh->y);
	printf("Rotate X = %i\n", (*tm)->sh->r_x);
	printf("Rotate Y = %i\n", (*tm)->sh->r_y);
	printf("Count = %i\n", (*tm)->sh->c);
	while (++j < (*tm)->sh->y)
	{
		i = -1;
		while ((*tm)->sh->sm[j][++i]){
		printf("%c", (*tm)->sh->sm[j][i]);
		}
		printf("\n");
	}
	j = -1;
	while (++j < (*tm)->sh->c)
	{
		printf("%i  ", (*tm)->sh->p->y[j]);
		printf("%i\n", (*tm)->sh->p->x[j]);
	}
}