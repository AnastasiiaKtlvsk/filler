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

int		main(void)//(int argc, char **argv)
{
	t_map* tm;

	// int fd;

	// fd = open(argv[1], O_RDONLY);

	tm = (t_map*)ft_memalloc(sizeof(t_map));
	int i = 1;
	read_specification(&tm, -1);
	char *temp;
	while (i++ < 3)
	{

		create_map(&tm);
	//print_map(&tm);

	
		create_shape(&tm);
	//print_shape(&tm);
		create_positions_arr(&tm);

	//printf("R %i\n", tm->ps->r);
	//ft_printf("%i %i\n", tm->ps->ap->y[tm->ps->r] - tm->sh->r_y, tm->ps->ap->x[tm->ps->r] - tm->sh->r_x);
//	printf("%i %i\n", tm->ps->ap->y[tm->ps->r] - tm->sh->r_y, tm->ps->ap->x[tm->ps->r] - tm->sh->r_x);
		//ft_putnbr(tm->ps->ap->y[tm->ps->r] - tm->sh->r_y);
		//ft_putchar(' ');
		//ft_putnbr(tm->ps->ap->x[tm->ps->r] - tm->sh->r_x);

		free_map(&tm);
		
		//printf("kek\n");
		get_next_line(0, &temp);
		free(temp);
		// if (tm->ps->ap->y[tm->ps->r] - tm->sh->r_y == 0 &&
		// 	tm->ps->ap->x[tm->ps->r] - tm->sh->r_x == 0)
		// 	break;
	}

	free(tm);
//	printf("cheburek\n");
	return (0);
}
 