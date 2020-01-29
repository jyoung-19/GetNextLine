/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:34:04 by jyoung            #+#    #+#             */
/*   Updated: 2019/09/26 22:03:24 by jyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_line(const int fd, char **line, char **str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i])
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		tmp = ft_strdup(str[fd] + i + 1);
		if (!(*line) || !(tmp))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
		if (!(str[fd][0]))
			ft_strdel(&str[fd]);
	}
	else if (!(str[fd][i]))
	{
		if (!(*line = ft_strdup(str[fd])))
			return (-1);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if ((fd < 0) || (fd >= OPEN_MAX) || !(line) || (BUFF_SIZE <= 0))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(str[fd]))
			if (!(str[fd] = ft_strnew(1)))
				return (-1);
		if (!(tmp = ft_strjoin(str[fd], buff)))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (str[fd] && read_line(fd, line, str))
		return (1);
	return (0);
}
