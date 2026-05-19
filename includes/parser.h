/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:00:03 by mmusquer          #+#    #+#             */
/*   Updated: 2026/05/19 15:10:50 by mmusquer         ###   ########.fr       */
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

typedef enum e_type
{
	SPRITE,
	MAP,
}			t_type;

void		parsing(char **av, t_para *para);
void		do_gnl(t_para *para);

int			is_only_map_char(int i, t_para *para);
int			is_header(int i, t_para *para);
int			is_header_complete(t_para *para);

void		error_pars(char *msg, t_para *para);
int			is_line_space(char *str);

#endif