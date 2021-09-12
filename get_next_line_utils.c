/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: payong <payong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 02:56:48 by payong            #+#    #+#             */
/*   Updated: 2021/08/08 02:56:48 by payong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != 0)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(src);
	if (size == 0)
		return (j);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}

char	*ft_strdup(const char *s)
{
	char	*a;
	size_t	i;

	i = 0;
	if (!s)
		return NULL;
	while (s[i] != 0)
		i++;
	a = (char *)malloc(sizeof(char) * i + 1);
	if (!a)
		return (0);
	a[i] = 0;
	while (i--)
		a[i] = *(s + i);
	return (a);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*a;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1)
		return (ft_strdup(s2));
	k = -1;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	a = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!a)
		return (0);
	while (++k < i)
		a[k] = s1[k];
	k = -1;
	while (++k < j)
		a[k + i] = s2[k];
	a[i + j] = 0;
	return (a);
}

size_t	ft_strchr(char **s, char **str)
{
	size_t	i;
	char	*t;

	i = 0;
	if (!(*s))
		return (0);
	while ((*s)[i] != 0)
	{
		if ((*s)[i] == '\n')
		{
			*str = malloc(sizeof(char) * (i + 2));
			ft_strlcpy(*str, *s, i + 2);
			t = ft_strdup(*s + i + 1);
			free(*s);
			*s = ft_strdup(t);
			free(t);
			return (i);
		}
		i++;
	}
	return (0);
}