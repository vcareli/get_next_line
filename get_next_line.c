/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:44:43 by vinvieir          #+#    #+#             */
/*   Updated: 2023/01/30 14:13:35 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				qchar;
	int				i;
	char			c;
	char			buffer[BUFFER_SIZE];
	ssize_t			leitura;
	static char		*line;

	i = 0;
	qchar = 0;
	if (!fd || fd < 0)
		return (NULL);
	leitura = read(fd, &c, 1);
	while (leitura > 0)
	{
		if (c == '\n')
			break ;
		buffer[i++] = c;
		qchar++;
		if (i == BUFFER_SIZE)
			i = 0;
		leitura = read(fd, &c, 1);
	}
	if (leitura <= 0)
		return (NULL);
	line = (char *)malloc(qchar + 1);
	if (!line)
		return (NULL);
	buffer_to_str(i, qchar, line, buffer);
	if (verifie_si_vide(line, qchar) == NULL)
		free(line);
	return (verifie_si_vide(line, qchar));
}
