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

void	create_shape(t_sh** sh)
{
	char	*sp;
	char	**sizes;
	int		i;

	get_next_line(3, &sp);
	sizes = ft_strsplit(sp, ' ');
	free(sp);
	(*sh)->y = ft_atoi(sizes[1]);
	(*sh)->x = ft_atoi(delete_last_char(&(sizes[2])));
	i = -1;
	while (++i < 3)
		free(sizes[i]);
	free(sizes);
	find_shape_points(sh, 0, -1);
}

void	find_shape_points(t_sh** sh, int c, int j)
{
	char	*temp;
	int		i;

	(*sh)->p = (t_p*)ft_memalloc(sizeof(t_p));
	(*sh)->p->x = ft_memalloc(sizeof(int) * (*sh)->x * (*sh)->y);
	(*sh)->p->y = ft_memalloc(sizeof(int) * (*sh)->x * (*sh)->y);
	while (++j < (*sh)->y)
	{
		get_next_line(3, &temp);
		i = -1;
		while (temp[++i])
		{			
			if (temp[i] == '*')
			{
				if (c == 0)
				{
					(*sh)->r_y = j;
					(*sh)->r_x = i;
				}
				(*sh)->p->y[c] = j - (*sh)->r_y;
				(*sh)->p->x[c++] = i - (*sh)->r_x;
			}
		}
		free(temp);
	}
}

void	free_shape(t_sh** sh)
{
	free((*sh)->p->x);
	free((*sh)->p->y);
	free((*sh)->p);
	free((*sh));
}


void	print_shape(t_sh** sh)
{
	int j = -1;

	printf("Shape X = %i\n", (*sh)->x);
	printf("Shape Y = %i\n", (*sh)->y);
	printf("Rotate X = %i\n", (*sh)->r_x);
	printf("Rotate Y = %i\n", (*sh)->r_y);
	while (++j < (*sh)->y * (*sh)->x)
	{
		printf("%i  ", (*sh)->p->y[j]);
		printf("%i\n", (*sh)->p->x[j]);
	}
}