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

char	*output_str(int fd, char *a)
{
	int		i;
	char	*t;
	char	*str;
	char	*z;

	str = 0;
	while (1)
	{
		i = 0;
		while (a[i] != '\n' && a[i] != 0)
			i++;
		if (a[i] == '\n')
		{
			t = malloc(sizeof(char) * (i + 2));
			ft_strlcpy(t, a, i + 2);
			z = ft_strjoin(str, t);
			free(t);
			free(str);
			return (z);
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
	char		*out;

	str = NULL;
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
	{
		free(t);
		free(leftover);
		free(str);
		return (0);
	}
	a[i] = 0;
	str = output_str(fd, a);
	if (!leftover & !t)
	{
		carl(a, &leftover);
		return (str);
	}
	carl(a, &leftover);
	out = ft_strjoin(t, str);
	free(str);
	free(t);
	return (out);
}
/* 
int main()
{
	int fd;
	char *str;
	int	i;

	fd = open("cheese.txt", O_RDWR);
	i = 1;
	while (i < 2)
	{
		str = get_next_line(fd);
		printf("output %d = %s", i, str);
		i++;
		free(str);
	}
} */