/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:20:17 by dholiday          #+#    #+#             */
/*   Updated: 2019/06/04 18:28:40 by mkami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit <FILENAME>");
		return (0);
	}
	return (main_help(argv[1]));
}

int		main_help(char *argv)
{
	int		fd;
	char	*str;
	int		f;
	t_etris *new;

	if ((fd = open(argv, O_RDONLY)) > 0)
	{
		str = ft_read(fd);
		f = ft_valid(str);
		if (f > 0 && f < 27)
		{
			new = ft_separate2(str, f);
			if (ft_check_figure(new) == 0)
				ft_putendl("error");
			else
				check_r_and_rotate(new, f);
			ft_clean_list(new);
			free(str);
			return (0);
		}
		free(str);
	}
	ft_putendl("error");
	return (0);
}

void	ft_clean_list(t_etris *new)
{
	t_etris *temp;

	while (new != NULL)
	{
		temp = new->next;
		free(new);
		new = temp;
	}
}

char	*ft_read(int fd)
{
	char	*str;
	int		i;
	char	buf[BUFF_SIZE + 1];
	char	*new;

	str = ft_memalloc(1);
	if (fd < 0 || read(fd, buf, 0) < 0)
		return (NULL);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		new = str;
		str = ft_strjoin(new, buf);
		free(new);
	}
	return (str);
}

t_etris	*ft_separate2(char *str, int f)
{
	int		i;
	t_etris *new;

	i = 1;
	ft_change_figure(str);
	new = ft_new_tetrimino(str, 0);
	while (i < f)
	{
		ft_tetrimino_push_back(new, ft_new_tetrimino(str, i));
		i++;
	}
	return (new);
}
