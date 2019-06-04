/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:58:37 by dholiday          #+#    #+#             */
/*   Updated: 2019/05/23 13:58:41 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_valid(char *str)
{
	int i;
	int k;
	int f;

	f = ft_count_figure(str);
	i = 0;
	k = ft_strlen(str);
	if (k != (f * 4 * 5 + f - 1))
		return (0);
	if ((f * 4) != ft_valid_char(str))
		return (0);
	return (f);
}

int		ft_count_figure(char *str)
{
	int i;
	int f;
	int d;

	i = 0;
	f = 0;
	d = 0;
	while (str[i] != '\0')
	{
		d++;
		if (str[i] == '\n')
			if (str[i + 1] == '\n')
			{
				if (d != 20)
					return (0);
				else
					d = -1;
				f++;
			}
		i++;
	}
	f++;
	return (f);
}

void	ft_change_figure(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == '\n')
			if (str[i + 1] == '\n')
				str[i + 1] = '*';
}

int		ft_valid_char(char *str)
{
	int i;
	int c;

	i = -1;
	c = 0;
	while (str[++i] != '\0')
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		if (str[i] == '#')
			c++;
	}
	return (c);
}
