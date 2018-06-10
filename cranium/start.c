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

	int fd = open(argv[1], O_RDONLY);
	tm = (t_map*)ft_memalloc(sizeof(t_map));
	read_specification(&tm);
	create_map(&tm);
	print_map(&tm);
	free_map(&tm);
	while (1==1);
	return (0);
}
