/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:20:17 by dholiday          #+#    #+#             */
/*   Updated: 2019/06/03 22:18:10 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_wide_n_high(t_etris *new)
{
	int i;
	int j;

	new->wide = 0;
	new->high = 0;
	new->antiwide = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (new->a[i][j] == 1)
			{
				new->high++;
				break ;
			}
			j++;
		}
		i++;
	}
	ft_check_wide_n_high2(new);
}

void	ft_check_wide_n_high2(t_etris *new)
{
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (new->a[i][j] == 1)
			{
				if (j >= new->f_y)
					new->wide++;
				else
					new->antiwide++;
				break ;
			}
			i++;
		}
		j++;
	}
}

void	ft_tetrcod(char *str, t_etris *tmp, int k)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tmp->a[i][j] = str[k] == '#' ? 1 : 0;
			k++;
			j++;
		}
		k++;
		i++;
	}
}

t_etris	*ft_new_tetrimino(char *str, int i)
{
	t_etris	*tmp;

	tmp = (t_etris*)malloc(sizeof(t_etris));
	if (!(tmp))
		return (NULL);
	if (str != NULL)
		ft_tetrcod(str, tmp, i * 21);
	tmp->next = NULL;
	tmp->s = 65 + i;
	ft_first_position(tmp);
	ft_check_wide_n_high(tmp);
	tmp->best_i = -1;
	tmp->best_j = -1;
	return (tmp);
}

void	ft_first_position(t_etris *new)
{
	int i;
	int j;
	int m;

	i = 0;
	m = 5;
	while (i < 4 && m == 5)
	{
		j = 0;
		while (j < 4)
		{
			if (new->a[i][j] == 1)
			{
				new->f_y = j;
				new->f_x = i;
				m = 0;
				break ;
			}
			j++;
		}
		i++;
	}
}
