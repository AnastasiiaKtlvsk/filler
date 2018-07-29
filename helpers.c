/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:11:58 by akotilie          #+#    #+#             */
/*   Updated: 2018/06/09 15:12:00 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cranium.h"

char*	delete_last_char(char **s)
{
    int i;

    i = 0;
    while ((*s)[i] != '\0')
        i++;
    (*s)[i - 1] = '\0';
    return (*s);
}

int		index_first_char(char **s, char c)
{
	int i;

	i = 0;
	while ((*s)[i] && (*s)[i] != c)
		i++;
	if (!(*s)[i])
		return (-1);
	return (i);
}