/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:25:21 by opanikov          #+#    #+#             */
/*   Updated: 2024/05/06 14:00:04 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char *tmp)
{
	int		i;
	char	*str;

	i = 0;
	if (!tmp[i])
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		str[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
	{
		str[i] = tmp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_right_line(char *tmp)
{
	char	*new_tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	new_tmp = (char *)malloc(sizeof(char) * (ft_strlen_gnl(tmp) - i + 1));
	if (!new_tmp)
		return (NULL);
	i++;
	while (tmp[i])
		new_tmp[j++] = tmp[i++];
	new_tmp[j] = '\0';
	free(tmp);
	return (new_tmp);
}

char	*ft_read(char *tmp, int fd)
{
	char	*buf;
	int		i;

	i = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	while (!ft_strchr_gnl(buf, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
		{
			free(buf);
			free(tmp);
			tmp = NULL;
			buf = NULL;
			return (NULL);
		}
		buf[i] = '\0';
		tmp = ft_strjoin_gnl(tmp, buf);
	}
	free(buf);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*str;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	tmp = ft_read(tmp, fd);
	if (!tmp)
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	str = ft_new_line(tmp);
	tmp = ft_right_line(tmp);
	return (str);
}

// #include <unistd.h>
// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd;
// 	fd = open("cat.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 6)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		i++;
// 		free(line);
// 	}
// 	close(fd);
// 	system ("leaks a.out");
// 	return (0);
// }
