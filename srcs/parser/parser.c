/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:21 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/18 17:51:16 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_line(char *path, t_para *para)
{
	int		fd;
	char	*line;
	int		n_line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_end("Error: cannot open file\n", para);
	n_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		n_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (n_line == 0)
		error_end("Error: empty file\n", para);
	return (n_line);
}

void	do_gnl(t_para *para)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	para->stock = malloc(sizeof(char *) * (count_line(para->path, para) + 1));
	if (!para->stock)
		error_end("Error: malloc fail\n", para);
	fd = open(para->path, O_RDONLY);
	if (fd < 0)
		error_end("Error: cannot open file\n", para);
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		para->stock[i] = line;
		line = get_next_line(fd);
		i++;
	}
	para->stock[i] = NULL;
	close(fd);
}

void	parsing(char **av, t_para *para)
{
	do_gnl(para);
}