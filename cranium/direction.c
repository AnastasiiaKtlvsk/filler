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

void	create_positions_arr(t_map** tm, t_sh** sh)
{

}
void	positions(t_map** tm, t_sh** sh, t_ps** ps) //s = 0
{
	int	i;
	int j;

	j = -1;
	ps = (t_ps*)ft_memalloc(sizeof(t_ps));
	ps->p = (t_p*)ft_memalloc(sizeof(t_p));
	ps->p->x = (int*)ft_memalloc(sizeof(int) * (*sh)->c);
	ps->p->y = (int*)ft_memalloc(sizeof(int) * (*sh)->c);
	ps->c = (int*)ft_memalloc(sizeof(int) * (*sh)->c);
	while ((*tm)->map[++j])
	{
		i = -1;
		while ((*tm)->map[j][++i])
		{
			check_position(t_map** tm, int x, int y, t_sh** sh)
			s = 0;
			c = (*sh)->c - 1;
			while (c >= 0)
			{
				if ((*tm)->map[j + (*sh)->y[c]][i + (*sh)->y[c]] == '*')
					s++;
				if ((*tm)->map[j + (*sh)->y[c]][i + (*sh)->y[c]])
					c = -5;
				c--;
			}
			if (s == 1 && c == -1)
			
		}
	}
}

void	check_position(t_map** tm, int x, int y, t_sh** sh)
{
	int p_c;
	int c;

	c = (*sh)->c - 1;
	while (c >= 0)
	{
		if ()
	}

}