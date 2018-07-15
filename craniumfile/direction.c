/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:11:32 by akotilie          #+#    #+#             */
/*   Updated: 2018/06/09 15:11:35 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cranium.h"

void	create_positions_arr(t_map** tm)
{	
	(*tm)->ps = (t_ps*)ft_memalloc(sizeof(t_ps));
	(*tm)->ps->ap = (t_p*)ft_memalloc(sizeof(t_p));
	(*tm)->ps->ap->x = (int*)ft_memalloc(sizeof(int) * (*tm)->sh->c);
	(*tm)->ps->ap->y = (int*)ft_memalloc(sizeof(int) * (*tm)->sh->c);
	//printf("ps is allocated\n");
	positions(tm, -1, 0, -1);
	//printf("points are added\n");
	find_best_point(tm);
	//printf("result\n");
}

void	print_arrays(t_map** tm)
{
	int	i;

	i = -1;
	printf("c %i\n", (*tm)->sh->c);
	while (++i < 30)
	{
		printf("y %i", (*tm)->sh->p->y[i]);
		printf(" x %i\n", (*tm)->sh->p->x[i]);
	}
}

void	positions(t_map** tm, int j, int p, int i) //j = -1, p = 0, i = -1
{
	int s;
	int c;

	c = (*tm)->sh->c;
	//print_arrays(tm);
	while ((*tm)->map[++j])
	{
		i = -1;
	//	printf("map position %p\n",  &((*tm)->map[j]));
	//printf("%s : %i %i\n", "Coordinates: ", j, i);
	//printf("%s : %i \n", "c: ",c);

		//printf("%s : %p\n", " (*tm)->sh->p->y[c]", &((*tm)->sh->p->y[c]));
		while ((*tm)->sh->p->y[c - 1] + j < (*tm)->y && (*tm)->map[j][++i])
		{
			s = 0;
			//printf("%s : %i %i\n", "Coordinates2: ", j, i);
		//	printf("%s : %i\n", "(*tm)->sh->p->y[c] + j", (*tm)->sh->p->y[0] + j);
			while (--c >= 0 && (*tm)->sh->p->y[c] + j < (*tm)->y)
			{
				((*tm)->map[j + (*tm)->sh->p->y[c]][i + (*tm)->sh->p->x[c]]
				== (*tm)->l) ? s++ : 0;
				(!(*tm)->map[j + (*tm)->sh->p->y[c]][i + (*tm)->sh->p->x[c]] || (*tm)->el ==
					(*tm)->map[j + (*tm)->sh->p->y[c]][i + (*tm)->sh->p->x[c]]) ? c = -5 : 0;
			}
			(s == 1 && c == -1) ? (*tm)->ps->ap->y[p] = j : 0;
			(s == 1 && c == -1) ? (*tm)->ps->ap->x[p++] = i  : 0;
			(s == 1 && c == -1) ? (*tm)->ps->c++ : 0;
		//	(s == 1 && c == -1) ? printf("%s : %i %i\n", "Add point", j, i) : 0;
			c = (*tm)->sh->c;
		}
	}
}

void	find_best_point(t_map** tm)
{
	int	i;
	int j;
	int k;
	int c;

	i = -1;
	c = 2147483647;
//	printf("(*tm)->ce %i\n",(*tm)->ce);
//	printf("(*tm)->ps->c %i\n", (*tm)->ps->c);

	while (++i < (*tm)->ce)
	{
		j = -1;
		while (++j < (*tm)->ps->c)
		{
			k = -1;
			while (++k < (*tm)->sh->c)
			{
				if (c >= find_distance_in_square((*tm)->ps->ap->x[j] + (*tm)->sh->p->x[k],
			 (*tm)->ps->ap->y[j] + (*tm)->sh->p->y[k], (*tm)->p->x[i], (*tm)->p->y[i]))
				{
					c = find_distance_in_square((*tm)->ps->ap->x[j] + (*tm)->sh->p->x[k],
			 (*tm)->ps->ap->y[j] + (*tm)->sh->p->y[k], (*tm)->p->x[i], (*tm)->p->y[i]);
				(*tm)->ps->r = j;
			}
				//printf("Distance %i y %i x %i\n", find_distance_in_square((*tm)->ps->ap->x[j] + (*tm)->sh->p->x[k],
			 //(*tm)->ps->ap->y[j] + (*tm)->sh->p->y[k], (*tm)->p->x[i], (*tm)->p->y[i]), (*tm)->ps->ap->y[j] + (*tm)->sh->p->y[k],(*tm)->ps->ap->x[j] + (*tm)->sh->p->x[k] );
			}


		}
	}
//	printf("Coefficient: %i\n", c);
//	printf("r: %i\n", (*tm)->ps->r);
}

int		find_distance_in_square(int x1, int y1, int x2, int y2)
{
	return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
}
