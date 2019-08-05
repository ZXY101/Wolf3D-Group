/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:11:24 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/03 18:10:21 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_read_line(int fd, char **line, char **sstr, int ret)
{
	int			i;
	char		*tmp;

	i = 0;
	while (sstr[fd][i] != '\n' && sstr[fd][i] != '\0')
		i++;
	if (sstr[fd][i] == '\n')
	{
		*line = ft_strsub(sstr[fd], 0, i);
		tmp = ft_strdup(sstr[fd] + i + 1);
		free(sstr[fd]);
		sstr[fd] = tmp;
		if (sstr[fd][0] == '\0')
			ft_strdel(&sstr[fd]);
	}
	else if (sstr[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(sstr[fd]);
		ft_strdel(&sstr[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*sstr[MAX_FD];
	char		*tmp;
	char		buff[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || line == NULL || BUFF_SIZE == 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (sstr[fd] == NULL)
			sstr[fd] = ft_strnew(0);
		tmp = ft_strjoin(sstr[fd], buff);
		free(sstr[fd]);
		sstr[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (sstr[fd] == NULL || sstr[fd][0] == '\0'))
		return (0);
	return (ft_read_line(fd, line, sstr, ret));
}
