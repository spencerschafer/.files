/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 13:24:20 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/03 10:20:31 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define GPS_X 50
# define GPS_Y 2
# define INCX 1.2
# define INCY 1.2
# define DINCX 0.6
# define DINCY 0.6
# define SPC 15
# define ENV (*tab)[0][0]

# include "../libft/Includes/libft.h"

typedef struct	s_point
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			z;
}				t_point;

void			ft_draw_straight(int i, int j, t_point ****tab);
void			ft_draw_straight2(int i, int j, t_point ****tab, int y2);
void			ft_no_space(char *line, bool b);
int				ft_check_map(t_point ****tab);
void			ft_draw_tab(t_point ****tab, int i);
void			ft_fdf(t_point ****tab);
t_point			**ft_attribut(char *line, int y_pos, int x_pos);
void			ft_code_erreur(int code);

#endif
