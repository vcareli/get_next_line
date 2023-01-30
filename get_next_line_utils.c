/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:44:43 by vinvieir          #+#    #+#             */
/*   Updated: 2023/01/30 14:13:35 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*verifie_si_vide(char *t, int dernier_ligne)
{
	if (t[0] == '\0')
	{
		free(t);
		return (NULL);
	}
	else
	{
		t[dernier_ligne] = '\0';
	}
	return (t);
}

void	buffer_to_str(int index, int qtd_char, char *str, char *buff)
{
	int		buffere;
	int		buffers;
	int		linei;

	linei = 0;
	buffers = index - qtd_char % BUFFER_SIZE;
	buffere = index;
	if (buffers < 0)
		buffers += BUFFER_SIZE;
	while (buffers != buffere)
	{
		str[linei++] = buff[buffers++];
		if (buffers == BUFFER_SIZE)
			buffers = 0;
	}
}
