/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:44:43 by vinvieir          #+#    #+#             */
/*   Updated: 2023/01/31 14:13:35 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_buffer_to_char(int fd, char *left_str)
{
	char	*buff;
	int		aux_read;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	aux_read = 1;
	while (!ft_strchr(left_str, '\n') && aux_read != 0)
	{
		aux_read = read(fd, buff, BUFFER_SIZE);
		if (aux_read == -1)
		{
			free(buff);
			free(left_str);
			return (NULL);
		}
		buff[aux_read] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*lecture;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	lecture = ft_buffer_to_char(fd, lecture);
	if (!lecture)
		return (NULL);
	line = ft_get_line(lecture);
	lecture = ft_nstr(lecture);
	return (line);
}
