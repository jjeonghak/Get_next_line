/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghak <rlawjdgks318@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:26:43 by jeonghak          #+#    #+#             */
/*   Updated: 2022/01/24 11:14:12 by jeonghak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_strswap(char **s1, char **s2)
{
	free(*s1);
	*s1 = ft_strdup(*s2);
	free(*s2);
	return ;
}

static char	*ft_split_line(char **save_buf)
{
	size_t		cnt;
	char		*prefix;
	char		*suffix;

	cnt = 0;
	while (*(*save_buf + cnt) != '\0' && *(*save_buf + cnt) != '\n')
		cnt++;
	if (*(*save_buf + cnt) == '\n')
		cnt++;
	prefix = (char *)malloc(cnt + 1);
	if (prefix == NULL)
		return (NULL);
	ft_memcpy(prefix, *save_buf, cnt);
	*(prefix + cnt) = '\0';
	if (*(*save_buf + cnt) != '\0')
	{
		suffix = ft_strdup(*save_buf + cnt);
		ft_strswap(save_buf, &suffix);
	}
	else
	{
		free(*save_buf);
		*save_buf = NULL;
	}
	return (prefix);
}

char	*get_next_line(int fd)
{
	int			page;
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
	static char	*save_buf;

	if (save_buf == NULL)
		save_buf = ft_strdup("");
	if (fd >= 0 && BUFFER_SIZE > 0 && save_buf != NULL)
	{
		while (!ft_strchr(save_buf, '\n'))
		{
			page = read(fd, buf, BUFFER_SIZE);
			if (page < 1)
				break ;
			buf[page] = '\0';
			temp = ft_strjoin(save_buf, buf);
			ft_strswap(&save_buf, &temp);
		}
		if (*save_buf != '\0')
			return (ft_split_line(&save_buf));
	}
	free(save_buf);
	save_buf = NULL;
	return (NULL);
}
