/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:44:43 by vinvieir          #+#    #+#             */
/*   Updated: 2023/01/28 14:13:35 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				qchar;
	int				qline;
	//ssize_t			qtd_lida;
	char			c;
	//char			lbuffer[1000];
	char		*ligne;

	qline = 1;
	qchar = 0;
	if (!fd || fd < 0)
		return (NULL);
	while(read(fd, &c, 1) == 1)
	{
		if (c == '\n')
		{
			qchar = 0;
			qline++;
		}
		else
			qchar++;
		if (qline > 10)
			break;
	}
	ligne = (char *)malloc(sizeof(char) * (qchar + 1));
	if (!ligne)
		return (NULL);
	if (read(fd, ligne, qchar) < 0)
	{
		free(ligne);
		return (NULL);
	}
	ligne[qchar] = '\0';
	return (ligne);
}
