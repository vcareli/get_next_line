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

static void	buffer_to_str(int fd, char **str, char *buff)
{
	int		lecture;
	char	*aux;

	if (!*str || !ft_strchr(*str, '\n'))
	{
		lecture = read(fd, buff, BUFFER_SIZE);
		while (lecture > 0)
		{
			buff[lecture] = 0;
			if (!*str)
				*str = ft_substr(buff, 0, lecture);
			else
			{
				aux = *str;
				*str = ft_strjoin(*str, buff);
				free(aux);
			}
			if (ft_strchr(buff, '\n'))
				break ;
			lecture = read(fd, buff, BUFFER_SIZE);
		}
	}
	free(buff);
}

static char	*retour_ligne(char **str)
{
	int		i;
	int		j;
	char	*ligne_ret;
	char	*aux;

	if (!*str)
		return (NULL);
	if (!ft_strchr(*str, '\n'))
	{
		ligne_ret = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = 0;
		return (ligne_ret);
	}
	i = ft_strlen(*str);
	j = ft_strlen(ft_strchr(*str, '\n'));
	ligne_ret = ft_substr(*str, 0, i - j + 1);
	aux = *str;
	*str = ft_substr(ft_strchr(*str, '\n'), 1, j - 1);
	free(aux);
	return (ligne_ret);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!fd || fd < 0 || BUFFER_SIZE < 1 || read(fd, &buffer, 0) == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer_to_str(fd, &line, buffer);
	return (retour_ligne(&line));
}
