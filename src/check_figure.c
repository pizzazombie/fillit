/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:03:16 by dholiday          #+#    #+#             */
/*   Updated: 2019/05/23 14:03:19 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_figure(t_etris *new)
{
	while (new != NULL)
	{
		if (ft_check_fig(new->a) == 0)
			return (0);
		new = new->next;
	}
	return (1);
}

int		ft_check_fig(int a[4][4])
{
	int i;
	int j;
	int cod[4];
	int c;

	i = -1;
	c = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (a[i][j] == 1)
				cod[++c] = ft_check_neighboor(a, i, j);
	}
	c = ft_check_cod(cod);
	return (c);
}

int		ft_check_cod(int *cod)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (i < 4)
	{
		if (cod[i] == 0)
			return (0);
		if (cod[i] >= 2)
			c++;
		i++;
	}
	return (c);
}

int		ft_check_neighboor(int a[4][4], int i, int j)
{
	int n;

	n = 0;
	if ((i - 1) >= 0)
		if (a[i - 1][j] == 1)
			n++;
	if ((j - 1) >= 0)
		if (a[i][j - 1] == 1)
			n++;
	if (i != 3)
		if (a[i + 1][j] == 1)
			n++;
	if (j != 4)
		if (a[i][j + 1] == 1)
			n++;
	return (n);
}
