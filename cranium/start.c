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
	t_sh* sh;

	int fd = open(argv[1], O_RDONLY);
	tm = (t_map*)ft_memalloc(sizeof(t_map));
	read_specification(&tm);
	create_map(&tm);
	print_map(&tm);
	free_map(&tm);
	sh = (t_sh*)ft_memalloc(sizeof(t_sh));
	create_shape(&sh);
	print_shape(&sh);
	free_shape(&sh);

	while (1==1);
	return (0);
}
 