/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:30:17 by dholiday          #+#    #+#             */
/*   Updated: 2019/06/04 18:28:05 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 100
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_etris
{
	char			s;
	int				f_x;
	int				f_y;
	int				best_j;
	int				best_i;
	int				wide;
	int				high;
	int				antiwide;
	struct s_etris	*next;
	int				a[4][4];
}					t_etris;

typedef struct		s_kvadrat
{
	int				i;
	int				j;
	int				r;
}					t_kvadrat;

typedef struct		s_ize
{
	int				size;
	int				bestsize;
}					t_ize;

int					main_help(char *argv);
int					ft_b(t_etris *new, char **setka, t_ize size, char *str);
char				**ft_p(char **setka, t_etris *new, t_kvadrat a, char key);
int					ft_search_r(char **setka, int size);
int					ft_check_place(t_etris *new, char **setka, t_kvadrat b);
int					ft_valid(char *str);
int					ft_check_cod(int *cod);
int					ft_count_figure(char *str);
int					ft_valid_char(char *str);
int					ft_check_neighboor(int a[4][4], int i, int j);
int					ft_check_fig(int a[4][4]);
void				ft_change_figure(char *str);
int					ft_check_figure(t_etris	*new);
char				*ft_read(int fd);
t_etris				*ft_separate2(char *str, int f);
void				ft_tetrimino_push_back(t_etris	*begin_list, t_etris *new);
void				ft_check_wide_n_high2(t_etris *new);
void				ft_check_wide_n_high(t_etris *new);
void				ft_tetrcod(char *str, t_etris	*tmp, int k);
t_etris				*ft_new_tetrimino(char *str, int i);
void				ft_clean_list(t_etris *new);
void				ft_first_position(t_etris *new);
void				ft_create_result(int size, t_etris *neww);
void				ft_create_result2(int size, t_etris *neww, char **setka);
int					ft_put_it(t_etris *neww, char *str);
void				ft_print_setka(char **setka, int r);
void				check_r_and_rotate(t_etris *new, int f);
void				ft_clean_setka(char **setka);
void				ft_helper(t_kvadrat *b, t_ize *flag, int size);
int					ft_helper2(t_etris *new_elem,
		t_kvadrat b, int past, t_ize *size);
int					ft_sqrt(int nb);

#endif
