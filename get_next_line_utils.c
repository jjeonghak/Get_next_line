/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonghak <rlawjdgks318@naver.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:27:48 by jeonghak          #+#    #+#             */
/*   Updated: 2021/12/31 13:39:09 by jeonghak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*(s + cnt) != '\0')
		cnt++;
	return (cnt);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (dst == NULL && src == NULL)
		return (dst);
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	while (n--)
		*ptr1++ = *ptr2++;
	return (ptr1);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, len);
	*(ptr + len) = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	prelen;
	size_t	suflen;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	prelen = ft_strlen(s1);
	suflen = ft_strlen(s2);
	ptr = (char *)malloc(prelen + suflen + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, prelen);
	ft_memcpy(ptr + prelen, s2, suflen);
	*(ptr + prelen + suflen) = '\0';
	return (ptr);
}
