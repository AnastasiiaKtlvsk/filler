/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:35:25 by akotilie          #+#    #+#             */
/*   Updated: 2018/06/09 16:35:27 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cranium.h"

int		main(void)
{
	t_map* tm;
	tm = (t_map*)ft_memalloc(sizeof(t_map));

	read_specification(&tm, -1);
	char *temp;
	while (1 == 1)
	{
		create_map(&tm);
		create_shape(&tm);
		create_positions_arr(&tm);
		ft_putnbr(tm->ps->ap->y[tm->ps->r] - tm->sh->r_y);
		ft_putchar(' ');
		ft_putnbr(tm->ps->ap->x[tm->ps->r] - tm->sh->r_x);
		ft_putchar('\n');
		free_map(&tm);
		if (get_next_line(0, &temp) < 1)
			break;
		free(temp);
		if (tm->ps->ap->y[tm->ps->r] - tm->sh->r_y == 0 &&
	 	tm->ps->ap->x[tm->ps->r] - tm->sh->r_x == 0)
			break;
	}
	//free(tm);
	return (0);
}
 