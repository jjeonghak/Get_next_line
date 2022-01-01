/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghak <rlawjdgks318@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:26:43 by jeonghak          #+#    #+#             */
/*   Updated: 2021/12/31 14:19:26 by jeonghak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_split_line(char **save_buf)
{
	size_t		cnt;
	char		*prefix;
	char		*suffix;

	cnt = 0;
	if (*save_buf == NULL)
		return (NULL);
	while (*(*save_buf + cnt) != '\0' && *(*save_buf + cnt) != '\n')
		cnt++;
	if (*(*save_buf + cnt) == '\n')
		cnt++;
	prefix = (char *)malloc(cnt + 1);
	if (prefix == NULL)
		return (NULL);
	ft_memcpy(prefix, *save_buf, cnt);
	*(prefix + cnt) = '\0';
	if (*(*save_buf + cnt - 1) == '\n' && *(*save_buf + cnt) != '\0')
	{
		suffix = ft_strdup(*save_buf + cnt + 1);
		free(*save_buf);
		*save_buf = suffix;
	}
	else
		free(*save_buf);
	return (prefix);
}

char	*get_next_line(int fd)
{
	int			page;
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
	static char	*save_buf[OPEN_MAX];
	if (save_buf[fd] == NULL)
		save_buf[fd] = ft_strdup("");
	if (fd > 0 && BUFFER_SIZE > 0 && save_buf[fd] != NULL)
	{
		while (!ft_strchr(save_buf[fd], '\n'))
		{
			page = read(fd, buf, BUFFER_SIZE);
			if (page < 1)
				break ;
			buf[page] = '\0';
			temp = ft_strjoin(save_buf[fd], buf);
			free(save_buf[fd]);
			save_buf[fd] = temp;
		}
		if (*save_buf[fd] != '\0')
			return (ft_split_line(&save_buf[fd]));
	}
	free(save_buf[fd]);
	return (NULL);
}
