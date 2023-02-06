/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvieir <vinvieir@student.42quebec.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:44:43 by vinvieir          #+#    #+#             */
/*   Updated: 2023/02/06 14:13:35 by vinvieir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static void	buffer_to_str(int fd, char *buf, char **str)
{
	int		i;
	char	*tmp;

	if (!str[fd] || !ft_strchr(str[fd], '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		while (i > 0)
		{
			buf[i] = 0;
			if (!str[fd])
				str[fd] = ft_substr(buf, 0, i);
			else
			{
				tmp = str[fd];
				str[fd] = ft_strjoin(str[fd], buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			i = read(fd, buf, BUFFER_SIZE);
		}
	}
	free(buf);
}

static char	*retour_ligne(int fd, char **str)
{
	int		i;
	int		j;
	char	*ret;
	char	*tmp;

	if (!str[fd])
		return (0);
	if (!ft_strchr(str[fd], '\n'))
	{
		ret = ft_substr(str[fd], 0, ft_strlen(str[fd]));
		free(str[fd]);
		str[fd] = 0;
		return (ret);
	}
	i = ft_strlen(str[fd]);
	j = ft_strlen(ft_strchr(str[fd], '\n'));
	ret = ft_substr(str[fd], 0, i - j + 1);
	tmp = str[fd];
	str[fd] = ft_substr(ft_strchr(str[fd], '\n'), 1, j - 1);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str[OPEN_MAX];

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (0);
	}
	buffer_to_str(fd, buf, str);
	return (retour_ligne(fd, str));
}
