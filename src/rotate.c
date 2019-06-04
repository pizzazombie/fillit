/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:50:00 by mkami             #+#    #+#             */
/*   Updated: 2019/06/04 17:46:57 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i * i < nb)
	{
		i++;
	}
	return (i);
}

void	check_r_and_rotate(t_etris *new, int f)
{
	int		r;
	char	*str;
	int		i;

	str = ft_memalloc(f + 2);
	str[0] = ft_sqrt(f * 4);
	i = 1;
	while (i < f + 1)
	{
		str[i] = 65 + i - 1;
		i++;
	}
	r = -1;
	while (r == -1)
	{
		r = ft_put_it(new, str);
		str[0]++;
	}
	ft_create_result(r, new);
	free(str);
	str = NULL;
}

void	ft_create_result(int size, t_etris *neww)
{
	char		**setka;
	int			i;
	int			j;

	setka = (char **)malloc(sizeof(setka) * (size + 1));
	if (neww == NULL)
		i = 0;
	i = 0;
	while (i < size)
	{
		setka[i] = ft_memalloc(size + 1);
		j = 0;
		while (j < size)
		{
			setka[i][j] = '.';
			j++;
		}
		i++;
	}
	setka[i] = 0;
	ft_create_result2(size, neww, setka);
}

void	ft_create_result2(int size, t_etris *neww, char **setka)
{
	int			i;
	t_kvadrat	best;

	while (neww != NULL)
	{
		best.i = neww->best_i;
		best.j = neww->best_j;
		setka = ft_p(setka, neww, best, neww->s);
		neww = neww->next;
	}
	ft_print_setka(setka, size);
	i = 0;
	while (setka[i] != 0)
	{
		free(setka[i]);
		i++;
	}
	free(setka);
}
