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
	(*tm)->ps->ap->x = (int*)ft_memalloc(sizeof(int) * (*tm)->x * (*tm)->y);
	(*tm)->ps->ap->y = (int*)ft_memalloc(sizeof(int) * (*tm)->x * (*tm)->y);
	positions(tm, -1, 0, -1);
	int p[13];
		p[0] = -1;
		p[1] = -1;
		p[2] = -1;
		p[3] = 0;
		p[4] = 0;
		p[5] = 2147483647;
		p[6] = (*tm)->x;
		p[7] = (*tm)->y;
		p[12] = (*tm)->l;
		find_best_point(tm, p);
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

void	positions(t_map** tm, int j, int p, int i)
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

void	find_best_point(t_map** tm, int *p)
{
	while (++p[0] < (*tm)->ce)
	{
		p[1] = -1;
		while (++p[1] < (*tm)->ps->c)
		{
			p[2] = -1;
			while (++p[2] < (*tm)->sh->c)
			{	
				p[8] = (*tm)->ps->ap->x[p[1]] + (*tm)->sh->p->x[p[2]];
				p[9] = (*tm)->ps->ap->y[p[1]] + (*tm)->sh->p->y[p[2]];
				p[10] = (*tm)->p->x[p[0]];
				p[11] = (*tm)->p->y[p[0]];
				if ((p[5] > fds(tm, p, 0, -1) || (p[3] == 0 && p[4] == 0)))
				{	
					p[5] = fds(tm, p, 0, -1);
					(*tm)->ps->r = p[1];
					p[4] = (*tm)->ps->ap->y[(*tm)->ps->r] - (*tm)->sh->r_y;
					p[3] = (*tm)->ps->ap->x[(*tm)->ps->r] - (*tm)->sh->r_x;
				}
			}
		}
	}
}

int		fds(t_map** tm, int *p, int c, int j)
{
	int r;
	int dx;
	int dy;
	int i;

	if (p[7] < 80)
	{

		dy = (p[12] == 'x') ? p[9] : (p[7] - p[9]);
		dx = (p[12] == 'x') ? p[8] * 20 : (p[6] - p[8]) * 20;
	}
	if (p[7] >= 80)
	{
		dy = (p[12] == 'x') ? (p[7] - p[9]) : p[9];
		dx = (p[12] == 'x') ? (p[6] - p[8]) : p[8];
	}
	r = ((p[8] - p[10]) * (p[8] - p[10])) + ((p[9] - p[11]) * (p[9] - p[11])) * 10;
	//r = (p[8] < p[10]) ? p[10] - p[8] : p[8] - p[10];
	//r = (p[9] < p[11]) ? r + p[11] - p[9] : r + p[9] - p[11];
	r = r + dx + dy;
	return (r);
}
