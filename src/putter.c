/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:20:17 by dholiday          #+#    #+#             */
/*   Updated: 2019/06/04 17:48:09 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_setka(char **setka, int r)
{
	int i;
	int j;

	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < r)
		{
			ft_putchar(setka[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		ft_put_it(t_etris *neww, char *str)
{
	char		**setka;
	t_kvadrat	p;
	t_ize		size;

	size.size = str[0];
	setka = (char **)malloc(sizeof(setka) * (size.size + 1));
	p.i = 0;
	while (p.i < size.size)
	{
		setka[p.i] = ft_memalloc(size.size + 1);
		p.j = 0;
		while (p.j < size.size)
		{
			setka[p.i][p.j] = '.';
			p.j++;
		}
		p.i++;
	}
	setka[p.i] = 0;
	size.bestsize = size.size;
	p.r = ft_b(neww, setka, size, str + 1);
	ft_clean_setka(setka);
	return (p.r);
}

int		ft_check_place(t_etris *new, char **setka, t_kvadrat b)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (new->a[i][j] == 1)
				if (setka[b.i + (i - new->f_x)][b.j + (j - new->f_y)] != '.')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_b(t_etris *new_elem, char **setka, t_ize size, char *str)
{
	t_kvadrat	b;
	int			past;
	t_ize		flag;

	if (new_elem == NULL)
		return (ft_search_r(setka, size.size));
	ft_helper(&b, &flag, size.size);
	while (++b.i < size.size - new_elem->high + 1)
	{
		b.j = new_elem->antiwide - 1;
		while ((++b.j < (size.size - new_elem->wide + 1)))
			if (setka[b.i][b.j] == '.' &&
					((ft_check_place(new_elem, setka, b)) == 1))
			{
				past = ft_b(new_elem->next,
						ft_p(setka, new_elem, b, new_elem->s), size, (str + 1));
				if (ft_helper2(new_elem, b, past, &size) == 1)
					return (past);
				setka = ft_p(setka, new_elem, b, '.');
				flag.bestsize = 0;
			}
	}
	return (past = (flag.bestsize == -5 ||
			(past == -1 && flag.size == 0)) ? -1 : size.bestsize);
}

char	**ft_p(char **setka, t_etris *new, t_kvadrat a, char key)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (new->a[i][j] == 1)
				setka[a.i + (i - new->f_x)][a.j + (j - new->f_y)] = key;
			j++;
		}
		i++;
	}
	return (setka);
}
