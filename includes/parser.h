/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:03 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/18 17:44:18 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct e_para
{
	char	**stock;
	char	*no_t;
	char	*so_t;
	char	*we_t;
	char	*ea_t;
	int		floor_c;
	int		ceiling_c;
	char	**map;
	char	*path;
}			t_para;

void		parsing(char **av, int fd, t_para *para);
void		error_end(char *msg, t_para *para);

#endif