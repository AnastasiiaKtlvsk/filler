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

int		main(int argc, char **argv)
{
	t_map* tm;

	int g;
	 int fd;

	 fd = open(argv[1], O_RDONLY);
//	printf("kek\n");
	tm = (t_map*)ft_memalloc(sizeof(t_map));
	int i = 1;
	read_specification(&tm, -1);

	char *temp;
	while (1 == 1)
	{

		create_map(&tm);
	//	print_map(&tm);

	
		create_shape(&tm);
		// print_shape(&tm);

		create_positions_arr(&tm);

	//printf("R %i\n", tm->ps->r);
	//ft_printf("%i %i\n", tm->ps->ap->y[tm->ps->r] - tm->sh->r_y, tm->ps->ap->x[tm->ps->r] - tm->sh->r_x);
 //	printf("%i %i\n", tm->ps->ap->y[tm->ps->r] - tm->sh->r_y, tm->ps->ap->x[tm->ps->r] - tm->sh->r_x);
		ft_putnbr(tm->ps->ap->y[tm->ps->r] - tm->sh->r_y);
		ft_putchar(' ');
		ft_putnbr(tm->ps->ap->x[tm->ps->r] - tm->sh->r_x);
		ft_putchar('\n');
		
		free_map(&tm);
		g = get_next_line(3, &temp);
		if (g < 1)
		{
		//	free(temp);
			break;
		}
		free(temp);
		// if (tm->ps->ap->y[tm->ps->r] - tm->sh->r_y == 0 &&
		// 	tm->ps->ap->x[tm->ps->r] - tm->sh->r_x == 0)
		// 	break;
	}

	free(tm);
		while (1==1);
//	printf("cheburek\n");
	return (0);
}
 