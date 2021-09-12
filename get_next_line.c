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

void	carl(char *a, char **str)
{
	int	i;

	*str = 0;
	i = 0;
	while (a[i] != '\n' && a[i] != 0)
		i++;
	if (a[i] == '\n')
		*str = ft_strdup(a + i + 1);
	i++;
}

char	*output_str(int fd, char *a, char *str)
{
	int		i;
	char	*t;

	while (1)
	{
		i = 0;
		while (a[i] != '\n' && a[i] != 0)
			i++;
		if (a[i] == '\n')
		{
			t = malloc(sizeof(char) * (i + 2));
			ft_strlcpy(t, a, i + 2);
			str = ft_strjoin(str, t);
			free(t);
			return (str);
		}
		else
		{
			t = ft_strjoin(str, a);
			free(str);
			str = ft_strdup(t);
			free(t);
			i = read(fd, a, BUFFER_SIZE);
			a[i] = 0;
			if (i == 0)
				return (str);
		}
	}
}

char	*get_next_line(int fd)
{
	static int	i;
	static char	a[BUFFER_SIZE + 1];
	char		*str;
	static char	*leftover;
	char		*t;

	str = ft_strdup("\0");
	/* if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL); */
	if (ft_strchr(&leftover, &str))
		return (str);
	else if (leftover)
	{
		t = ft_strdup(leftover);
		free(leftover);
		leftover = ft_strdup("\0");
	}
	else
		t = ft_strdup("\0");
	i = read(fd, a, BUFFER_SIZE);
	if (i == -1 || (i == 0 && !leftover))
		return (NULL);
	a[i] = 0;
	str = output_str(fd, a, str);
	if (!leftover & !t)
	{
		carl(a, &leftover);
		return (str);
	}
	carl(a, &leftover);
	return (ft_strjoin(t, str));
}
/* 
int main()
{
	int fd;
	char *str;
	int	i;

	fd = open("cheese.txt", O_RDWR);
	i = 1;
	while (i < 11)
	{
		str = get_next_line(fd);
		printf("output %d = %s", i, str);
		i++;
		free(str);
	}
} */